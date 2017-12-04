#ifndef CONTROL_HH
#define CONTROL_HH

#include "playership.hh"
#include "starsystem.hh"
#include "complex.hh"

class GameWindow;

namespace Student {
class Control : public QGraphicsRectItem
{
    // Configuration of player's controls and collision detection

    using SystemComplex = Complex<std::shared_ptr<Common::StarSystem>, QGraphicsEllipseItem*>;
public:
    Control(Student::Playership* player, GameWindow* gameWindow, std::vector<SystemComplex>& complex);
    ~Control();

    void keyPressEvent(QKeyEvent *event);
    std::shared_ptr<Common::StarSystem> checkCollideWithSystem();

private:
    Student::Playership* player_;
    GameWindow* gameWindow_;
    std::vector<SystemComplex>& complex_;

};
}//Student
#endif // CONTROL_HH
