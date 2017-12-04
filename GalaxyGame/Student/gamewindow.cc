#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    timer_(new QTimer(this)),
    timer2_(new QTimer(this)),
    timer3_(new QTimer(this)),
    shipName_(),
    difficulty_(0),
    loseAmount_(0),
    shipComplex_(),
    statistics_(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("GalaxyGame");

    connect(timer_, &QTimer::timeout, this, &GameWindow::update);
    connect(timer2_, &QTimer::timeout, this, &GameWindow::refresh);
    connect(timer3_, &QTimer::timeout, this, &GameWindow::payCheck);

    connect(ui->actionQuit_Game, &QAction::triggered, this, &GameWindow::quitGame);
    connect(ui->actionNew_Game, &QAction::triggered, this, &GameWindow::newGameSlot);
    connect(ui->rescueButton, &QPushButton::clicked, this, &GameWindow::rescueShip);
    connect(ui->scoreButton, &QPushButton::clicked, this, &GameWindow::openScoreboard);
}

GameWindow::~GameWindow()
{
    runner_ = nullptr;
    galaxy_ = nullptr;
    delete ui;
    delete timer_;
    delete timer2_;
    delete timer3_;
    delete statistics_;
    delete playership_;
    delete playerControl_;
    delete scene_;
    delete scoreboard_;

    for (auto iter = distressVector_.begin();iter!=distressVector_.end();iter++) {
        *iter = nullptr;
    }

    for (auto iter = shipComplex_.begin();iter!=shipComplex_.end();iter++) {
        delete iter->objectShape;
        iter->object = nullptr;
    }
}

void GameWindow::update()
{
    // Real-time commands here
    // NO LOOPS!

    ui->graphicsView->grabKeyboard();
    playerControl_->setFocus(); // Focus to control
    releaseMouse();

    auto collider = playerControl_->checkCollideWithSystem();
    showInfo(collider);

    if (checkDistress(collider)) {
        ui->rescueButton->setEnabled(true);
    }
    else {ui->rescueButton->setEnabled(false);}

    showStats();

    if (statistics_->getLostShips() >= loseAmount_) {
        gameOver();
    }
}

void GameWindow::centerOnPlayer()
{
    ui->graphicsView->centerOn(playership_->getItem());
}

void GameWindow::setDistressOn(std::shared_ptr<Common::Ship> ship)
{
    for (auto iter = shipComplex_.begin();iter!=shipComplex_.end();iter++) {
        if (iter->object == ship) {
            iter->objectShape->setBrush(Qt::GlobalColor::red);
            iter->objectShape->setZValue(1); // Highlight distressed ships
            if (!timerBit_) {
                // After first ship distressed, set timer2 longer
                timer2_->start(3000);
                timerBit_ = true;
            }
            return;
        }
    }
}

void GameWindow::setDistressOff(std::shared_ptr<Common::Ship> ship)
{
    for (auto iter = shipComplex_.begin();iter!=shipComplex_.end();iter++) {
        if (iter->object == ship) {
            iter->objectShape->setBrush(Qt::GlobalColor::yellow);
            iter->objectShape->setZValue(0); // Restore Z value
            return;
        }
    }
}

void GameWindow::refresh()
{
    runner_->createActions();
    runner_->doActions();
    updatePositions();
}

void GameWindow::onDataReceived(const QString& name, const int& diff)
{
    shipName_ = name;
    playership_->setName(name.toStdString()); // set ship name
    ui->nameLabel->setText(name);
    difficulty_ = unsigned(diff); // difficulty 1, 2 or 3
    timerBit_ = false;
    playership_->spawn();

    initGameSession(); // init ship graphics
    centerOnPlayer();
    showInfo(playerControl_->checkCollideWithSystem()); // get ship location info
    ui->rescueButton->setEnabled(false);

    timer_->start(50); // update called every [param] ms
    // Init longer period timer for executing long-term actions
    timer2_->start(200);
    // Credit income for player
    timer3_->start(12000);
}

void GameWindow::rescueShipPublic()
{
    if (ui->rescueButton->isEnabled()) {
        rescueShip();
    }
}

void GameWindow::initGameSession()
{
    int shipsToMake = 0;
    int startBalance = 0;

    switch (difficulty_) {
    case 1:
        startBalance = 1500;
        shipsToMake = Common::randomMinMax(15,30);
        break;
    case 2:
        startBalance = 2000;
        shipsToMake = Common::randomMinMax(30,45);
        break;
    case 3:
        startBalance = 3000;
        shipsToMake = Common::randomMinMax(45,60);
        break;
    default:
        throw Common::GameException("Error while handling game difficulty");
    }
    loseAmount_ = unsigned(0.3 * shipsToMake); // 40% of ships lost
    statistics_ = new Student::Statistics(startBalance);
    runner_->spawnShips(unsigned(shipsToMake));
    initComplex();
}

void GameWindow::initComplex()
{
    auto shipList = galaxy_->getShips();

    for (auto iter = shipList->begin(); iter!=shipList->end();iter++) {
        Common::Point position = iter->get()->getLocation()->getCoordinates();
        QGraphicsRectItem* item = new QGraphicsRectItem();
        item->setBrush(Qt::yellow);
        item->setRect(position.x*SCALE+2, position.y*SCALE+2, 10, 10);
        scene_->addItem(item);
        shipComplex_.push_back({*iter, item});
    }
}

void GameWindow::updatePositions()
{
    for (std::vector<ShipComplex>::const_iterator iter = shipComplex_.begin(); iter!=shipComplex_.end();iter++) {
        if (iter->object->getLocation() == 0) {
            // Ship is somewhere in the galaxy
            // Not in system, so hiding item from screen
            iter->objectShape->hide();
            continue;
        }
        Common::Point pos = iter->object->getLocation()->getCoordinates();
        if (iter->object->isAbandoned()) {
            // Ship is abandoned
            iter->objectShape->setBrush(Qt::GlobalColor::magenta);
        }
        iter->objectShape->setRect(pos.x*SCALE+2, pos.y*SCALE+2, 10, 10);
        iter->objectShape->show();
    }
}

void GameWindow::showStats()
{
    ui->infoSaved->setText(QString::number(statistics_->getSavedShips()));
    ui->infoLost->setText(QString::number(statistics_->getLostShips()));
    ui->infoPoints->setText(QString::number(statistics_->getPoints()));
    ui->infoCredits->setText(QString::number(statistics_->getCreditBalance()));
    ui->infoLose->setText(QString::number(loseAmount_ - statistics_->getLostShips()));
}

void GameWindow::resetGame()
{
    for (auto iter = shipComplex_.begin();iter!=shipComplex_.end();iter++) {
        scene_->removeItem(iter->objectShape);
        delete iter->objectShape;
        iter->object = nullptr;
    }
    shipComplex_.clear();
    galaxy_->removeAllShips();
    delete statistics_; // if new game started, old statistics is deallocated
}

void GameWindow::pauseTimers()
{
    timer_->stop();
    timer2_->stop();
    timer3_->stop();
    ui->graphicsView->releaseKeyboard();
}

void GameWindow::restartTimers()
{
    timer_->start();
    timer2_->start();
    timer3_->start();
}

bool GameWindow::checkDistress(std::shared_ptr<Common::StarSystem> system)
{
    distressVector_.clear();

    if (system != nullptr) {
        auto shipList = galaxy_->getShipsInStarSystem(system->getName());

        for (auto iter = shipList.begin();iter!=shipList.end();iter++) {
            auto ship = static_cast<Common::CargoShip*>(iter->get());

            if (ship != nullptr) {

                if (dynamic_cast<Common::DistressAction*>(ship->getAction().get()) != nullptr) {
                    distressVector_.push_back(std::static_pointer_cast<Common::CargoShip>(*iter));
                    return true;
                }
            }
        }
    }
    return false;
}

void GameWindow::addScore()
{
    QString name = shipName_;
    unsigned score = statistics_->getPoints();
    Student::ScoreBoard::Entry entry = {name, score};
    scoreboard_->addEntry(entry);
}

void GameWindow::setScoreboard(Student::ScoreBoard *scoreboard)
{
    scoreboard_ = scoreboard;
}

void GameWindow::gameOver()
{
    pauseTimers();

    QMessageBox *box = new QMessageBox(this);
    box->setText("GAME OVER");
    box->setInformativeText("Too many lost ships.\n"
                            "Please try again!\n"
                            "Your score was: " + QString::number(statistics_->getPoints()));
    box->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    box->setDefaultButton(QMessageBox::Ok);
    box->setButtonText(QMessageBox::Ok, "New Game");
    box->setButtonText(QMessageBox::Cancel, "Quit");

    int result = box->exec();

    if (result == QMessageBox::Cancel) {
        addScore();
        scoreboard_->saveScores();
        delete box;
        this->close();
        return;
    }
    delete box;
    newGame(false);
}

Student::Statistics *GameWindow::getStatistics() const
{
    return statistics_;
}

void GameWindow::setStatistics(Student::Statistics *statistics)
{
    statistics_ = statistics;
}

void GameWindow::setGalaxy(std::shared_ptr<Student::Galaxy> galaxy)
{
    galaxy_ = galaxy;
}

void GameWindow::setGameRunner(std::shared_ptr<Common::IGameRunner> gameRunner)
{
    runner_ = gameRunner;
}

void GameWindow::setPlayerShip(Student::Playership *ship)
{
    playership_ = ship;
}

void GameWindow::showInfo(std::shared_ptr<Common::StarSystem> system)
{
    clearInfo();
    if (system == nullptr) return;
    ui->infoEconomy->setText(Student::economyTypeToQstring(system->getEconomy()));
    ui->infoId->setText(QString::fromStdString(std::to_string(system->getId())));
    ui->infoPopulation->setText(QString::fromStdString(std::to_string(system->getPopulation())));
    ui->infoSysName->setText(QString::fromStdString(system->getName()));
    ui->infoSysShips->setText(QString::number(galaxy_->getShipsInStarSystem(
                                                  system->getName()).size()));
}

void GameWindow::clearInfo()
{
    ui->infoEconomy->setText("--");
    ui->infoId->setText("--");
    ui->infoPopulation->setText("--");
    ui->infoSysName->setText("--");
    ui->infoSysShips->setText("--");
}

QGraphicsView *GameWindow::getGraphicsView() const
{
    return ui->graphicsView;
}

void GameWindow::newGame(const bool &prompt=true)
{
    pauseTimers();

    // Implement for New Game button
    StartDialog *dialog = new StartDialog();
    QObject::connect(dialog, SIGNAL(passData(const QString&, const int&)),
                     this, SLOT(onDataReceived(const QString&, const int&)));
    dialog->setGameWindow(this);

    if (prompt) {
        QMessageBox *box = new QMessageBox(this);
        box->setText("Would you like to start a new game?");
        box->setInformativeText("Any progress will be lost.\n"
                                "New highscores will be saved.");
        box->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box->setDefaultButton(QMessageBox::Cancel);

        int value = box->exec();

        if (value == QMessageBox::Cancel) {
            delete dialog;
            delete box;
            restartTimers();
            return;
        }
        delete box;
    }
    this->hide();
    addScore();
    scoreboard_->saveScores();
    resetGame(); // Init states for new game
    dialog->show();
}

void GameWindow::quitGame()
{
    pauseTimers();

    QMessageBox *box = new QMessageBox(this);
    box->setText("Do you really want to quit?");
    box->setInformativeText("Any progress will be lost!\n"
                            "New highscores will be saved.");
    box->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    box->setDefaultButton(QMessageBox::Cancel);

    int value = box->exec();

    if (value == QMessageBox::Cancel) {
        delete box;
        restartTimers();
        return;
    }
    addScore();
    scoreboard_->saveScores();
    delete box;
    this->close();
}

void GameWindow::newGameSlot()
{
    newGame();
}

void GameWindow::rescueShip()
{
    if ((statistics_->getCreditBalance() - 500) < statistics_->MAX_LOAN_ALLOWANCE) {
        pauseTimers();

        QMessageBox *box = new QMessageBox(this);
        box->setText("Not enough credits to rescue ship!");
        box->setStandardButtons(QMessageBox::Ok);
        box->setDefaultButton(QMessageBox::Ok);
        box->exec();
        delete box;
        restartTimers();
        return;
    }
    if (distressVector_.empty()) return;
    auto ship = distressVector_.back();
    if (ship == nullptr) return;
    ship->getEngine()->repair(ship->getEngine()->getMaxHealth());
    ship->decideAction();
    ship->executeAction();
    distressVector_.pop_back();
    // Player saved ship
    statistics_->addSavedShip();
    statistics_->addPoints(100);
    statistics_->reduceCredits(500);
}

void GameWindow::payCheck()
{
    statistics_->addCredits(1000);
}

void GameWindow::openScoreboard()
{
    pauseTimers();
    QDialog *dialog = new QDialog(this);
    QFormLayout *layout = new QFormLayout(dialog);
    QPushButton *button = new QPushButton(dialog);
    button->setText("Close");
    connect(button, &QPushButton::clicked, dialog, &QDialog::close);
    dialog->setMinimumWidth(200);
    dialog->setWindowTitle("Highscores");
    dialog->setLayout(layout);

    int count = 1;
    auto entryList = scoreboard_->getBoard();
    for (auto iter = entryList.begin();iter!=entryList.end();iter++) {
        QString name = QString::number(count) + ". " + iter->first;
        QString score = QString::number(iter->second);
        layout->addRow(new QLabel(name), new QLabel(score));
        count++;
    }
    layout->addWidget(button);

    dialog->exec();
    delete button;
    delete layout;
    delete dialog;
    restartTimers();
}

void GameWindow::setPlayerControl(Student::Control *playerControl)
{
    playerControl_ = playerControl;
}

void GameWindow::setScene(QGraphicsScene *scene)
{
    scene_ = scene;
}
