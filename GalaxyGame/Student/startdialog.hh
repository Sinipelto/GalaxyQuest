#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include "playershipnamegenerator.hh"
#include <QDialog>
#include <QMessageBox>

class GameWindow;

namespace Ui {
class StartDialog;
}

// The starting window, used to configure the options

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();

    void setGameWindow(GameWindow* gameWindow);

private slots:
    void startGame();
    void generateName();
    void showInstructions();
    void dataChanged();
    void quit();

signals:
    void passData(const QString& name, const int& diff);

private:
    Ui::StartDialog *ui;
    Student::PlayerShipNameGenerator* nameGen_;
    GameWindow* gameWindow_;

};
#endif // STARTDIALOG_HH
