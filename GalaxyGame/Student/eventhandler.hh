#ifndef EVENTHANDLER_HH
#define EVENTHANDLER_HH

#include "ieventhandler.hh"
#include "point.hh"
#include "ship.hh"
#include "starsystem.hh"
#include "gamewindow.hh"
#include "gameexception.hh"

namespace Student {
class EventHandler: public Common::IEventHandler
{
public:
    EventHandler(GameWindow* game);
    ~EventHandler();
    void shipSpawned(std::shared_ptr<Common::Ship> ship);
    void shipRemoved(std::shared_ptr<Common::Ship> ship);
    void shipRelocated(std::shared_ptr<Common::Ship> ship,
                       std::shared_ptr<Common::StarSystem> starSystem);
    void shipMoved(std::shared_ptr<Common::Ship> ship,
                   Common::Point origin,
                   Common::Point target);
    void exceptionInExecution(std::shared_ptr<Common::Ship> ship, std::string const& msg);
    void distressOn(std::shared_ptr<Common::Ship> ship);
    void distressOff(std::shared_ptr<Common::Ship> ship);
    void shipAbandoned(std::shared_ptr<Common::Ship> ship);

private:
    GameWindow* game_;

};
}//Student

#endif // EVENTHANDLER_HH
