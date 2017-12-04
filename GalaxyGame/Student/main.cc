#include "gamewindow.hh"
#include "startdialog.hh"
#include "ieventhandler.hh"
#include "eventhandler.hh"
#include "galaxy.hh"
#include "igamerunner.hh"
#include "complex.hh"
#include "wormholedrive.hh"
#include "control.hh"
#include "initialize.hh"
#include "utility.hh"
#include "playership.hh"
#include "point.hh"
#include "tools.hh"
#include <QObject>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>
#include <memory>
#include <time.h>

#include "scoreboard.hh"

GameWindow* initGameWindow()
{
    return new GameWindow();
}

StartDialog* initDialogWindow(GameWindow* game)
{
    StartDialog *dialog = new StartDialog();

    // Connect emit signal
    QObject::connect(dialog, SIGNAL(passData(const QString&, const int&)),
                     game, SLOT(onDataReceived(const QString&, const int&)));
    return dialog;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Window initializations
    GameWindow* game = initGameWindow();
    StartDialog* dialog = initDialogWindow(game);

    std::shared_ptr<Common::IEventHandler> handler = std::make_shared<Student::EventHandler>(game);
    std::shared_ptr<Student::Galaxy> galaxy = std::make_shared<Student::Galaxy>();
    std::shared_ptr<Common::IGameRunner> gameRunner = Common::getGameRunner(galaxy, handler);
    Common::utilityInit(time(NULL));

    // Object initializations

    // Vector for system and graphic item binding
    std::vector<Complex<std::shared_ptr<Common::StarSystem>, QGraphicsEllipseItem*>> complexVector;

    // Get ui graphicsView
    QGraphicsView *view = game->getGraphicsView();

    // Initialize scene
    QGraphicsScene *scene = new QGraphicsScene();

    // Init player engine
    std::shared_ptr<Common::WormHoleDrive> whd = std::make_shared<Common::WormHoleDrive>(galaxy);

    // Init player ship
    Student::Playership *playership = new Student::Playership(whd, galaxy->getRandomSystem(), handler, galaxy);

    // Initialize control
    Student::Control *control = new Student::Control(playership, game, complexVector);

    // Initialize scoreboard
    Student::ScoreBoard *scoreboard = new Student::ScoreBoard();

    // Playspace configurations
    game->setGalaxy(galaxy);
    game->setGameRunner(gameRunner);
    game->setPlayerShip(playership);
    game->setPlayerControl(control);
    game->setScene(scene);
    game->setScoreboard(scoreboard);

    dialog->setGameWindow(game);

    view->setStyleSheet("background-color:black");
    view->setRenderHints(QPainter::Antialiasing);
    view->setScene(scene);

    scene->addItem(control);
    scene->addItem(playership->getItem()); // PLAYER ADDED HERE

    std::shared_ptr<Common::StarSystem::StarSystemVector> systemPointer = galaxy->getSystems();
    // Draw starsystems to the playing field
    for (Common::StarSystem::StarSystemVector::iterator iter = systemPointer->begin(); iter!=systemPointer->end(); iter++) {
        Common::Point coord = iter->get()->getCoordinates();
        QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
        ellipse->setRect(coord.x*SCALE, coord.y*SCALE, 16, 16);
        ellipse->setBrush(Qt::white);
        scene->addItem(ellipse);
        complexVector.push_back({*iter, ellipse});
    }

    dialog->show();
    return a.exec();
}
