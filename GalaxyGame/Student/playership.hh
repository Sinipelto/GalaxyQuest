#ifndef PLAYERSHIP_HH
#define PLAYERSHIP_HH

#include "galaxy.hh"
#include "ship.hh"
#include "point.hh"
#include "tools.hh"
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsRectItem>

namespace Student {
class Playership: public Common::Ship
{

// Configuration of the player's ship

public:
    Playership(std::shared_ptr<Common::ShipEngine> engine,
               std::shared_ptr<Common::StarSystem> initialLocation,
               std::shared_ptr<Common::IEventHandler> events,
               std::shared_ptr<Student::Galaxy> galaxy);

    ~Playership();

    bool decideAction(); // virtual
    void spawn();

    QGraphicsRectItem *getItem() const;
    std::shared_ptr<Common::StarSystem> getSpawnLocation() const;

private:
    void initGraphics();

    std::shared_ptr<Common::ShipEngine> engine_;
    std::shared_ptr<Common::StarSystem> initLocation_;
    std::shared_ptr<Common::IEventHandler> events_;
    std::shared_ptr<Student::Galaxy> galaxy_;
    std::shared_ptr<Common::IAction> currentAction_;

    std::string name_; // virtual
    bool abandoned_; // virtual

    QGraphicsRectItem *rectItem_;

};
}//Student

#endif // PLAYERSHIP_HH
