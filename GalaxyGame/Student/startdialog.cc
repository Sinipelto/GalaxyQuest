#include "startdialog.hh"
#include "ui_startdialog.h"
#include "gamewindow.hh"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog),
    nameGen_(new Student::PlayerShipNameGenerator()),
    gameWindow_(nullptr)
{
    ui->setupUi(this);
    ui->warningLabel->hide();
    setWindowTitle("GalaxyGame");

    connect(ui->startButton, &QPushButton::clicked, this, &StartDialog::startGame);
    connect(ui->randomizeButton, &QPushButton::clicked, this, &StartDialog::generateName);
    connect(ui->helpButton, &QPushButton::clicked, this, &StartDialog::showInstructions);
    connect(ui->closeButton, &QPushButton::clicked, this, &StartDialog::quit);
}

StartDialog::~StartDialog()
{
    delete ui;
    delete nameGen_;
}

void StartDialog::setGameWindow(GameWindow *gameWindow)
{
    gameWindow_ = gameWindow;
}

void StartDialog::startGame() {
    // Cleanups to name input
    QString strippedName = ui->nameField->text().replace(" ", "", Qt::CaseInsensitive)
            .replace(";", "", Qt::CaseInsensitive);

    if (strippedName.size() <= 0) {
        ui->nameField->clear();
        ui->warningLabel->show();
        return;
    }
    dataChanged();
    clearFocus();
    gameWindow_->show();
    this->close();
}

void StartDialog::dataChanged()
{
    emit passData(ui->nameField->text().replace(" ", "", Qt::CaseInsensitive).replace(";", "", Qt::CaseInsensitive),
                  ui->diffBox->value()); // Trimmed input
}

void StartDialog::quit()
{
    gameWindow_->close();
    this->close();
}

void StartDialog::generateName()
{
    QString name = nameGen_->getRandomName();
    ui->nameField->clear();
    ui->nameField->insert(name);
}

void StartDialog::showInstructions()
{
    QMessageBox *box = new QMessageBox(this);
    box->setWindowTitle("Game Instructions");
    box->setText("Use WASD to move your ship.\n"
                 "Use R or Rescue-button to rescue ships.\n\n"
                 "Your mission is to help distressed ships "
                 "until\nthere are too many abandoned ships in the galaxy.\n\n"
                 "white circle = Starsystem\n"
                 "blue square = Player ship\n"
                 "yellow square = NPC ship\n"
                 "red square = Distressed ship\n"
                 "purple square = Abandoned ship");
    box->setStandardButtons(QMessageBox::Ok);
    box->setDefaultButton(QMessageBox::Ok);
    box->exec();
    delete box;
}
