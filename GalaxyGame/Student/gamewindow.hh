#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include "galaxy.hh"
#include "cargoship.hh"
#include "igamerunner.hh"
#include "playership.hh"
#include "tools.hh"
#include "control.hh"
#include "utility.hh"
#include "statistics.hh"
#include "scoreboard.hh"
#include "distressaction.hh"
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class GameWindow;
}

// The main window of the game

using ShipComplex = Complex<std::shared_ptr<Common::Ship>, QGraphicsRectItem*>;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    void setGalaxy(std::shared_ptr<Student::Galaxy> galaxy);
    void setGameRunner(std::shared_ptr<Common::IGameRunner> gameRunner);
    void setPlayerShip(Student::Playership *ship);
    void setPlayerControl(Student::Control *playerControl);
    void setScene(QGraphicsScene* scene);
    void setStatistics(Student::Statistics *statistics);
    void setScoreboard(Student::ScoreBoard *scoreboard);
    void setDistressOn(std::shared_ptr<Common::Ship> ship);
    void setDistressOff(std::shared_ptr<Common::Ship> ship);

    QGraphicsView* getGraphicsView() const;
    Student::Statistics *getStatistics() const;

    void showInfo(std::shared_ptr<Common::StarSystem> system);
    void centerOnPlayer();
    void rescueShipPublic();

public slots:
    void onDataReceived(const QString& name, const int& diff);

private slots:
    void newGameSlot();
    void quitGame();
    void update(); // fast update
    void refresh(); // slow update
    void rescueShip();
    void payCheck();
    void openScoreboard();

private:
    void newGame(const bool& prompt);
    void gameOver();
    void clearInfo();
    void initGameSession();
    void initComplex();
    void updatePositions();
    void showStats();
    void resetGame();
    void pauseTimers();
    void restartTimers();
    bool checkDistress(std::shared_ptr<Common::StarSystem> system);
    void addScore();

    Ui::GameWindow *ui;

    QTimer* timer_;
    QTimer* timer2_;
    QTimer* timer3_;

    QString shipName_;
    unsigned difficulty_;
    unsigned loseAmount_;
    bool timerBit_;

    std::vector<ShipComplex> shipComplex_;
    std::vector<std::shared_ptr<Common::CargoShip>> distressVector_;

    std::shared_ptr<Common::IGameRunner> runner_;
    std::shared_ptr<Student::Galaxy> galaxy_;

    Student::Playership *playership_;
    Student::Control *playerControl_;
    Student::Statistics *statistics_;
    Student::ScoreBoard *scoreboard_;

    QGraphicsScene *scene_;
};

#endif // GAMEWINDOW_HH
