#include "ship.hh"
#include "iaction.hh"
#include "gameexception.hh"

namespace Common {

Ship::Ship(std::shared_ptr<ShipEngine> engine,
           std::shared_ptr<StarSystem> initialLocation,
           std::shared_ptr<IEventHandler> events)
    : engine_(engine),
      location_(initialLocation),
      events_(events),
      currentAction_(),
      name_("Heart of gold"),
      abandoned_(false)
{
}

std::shared_ptr<ShipEngine> Ship::getEngine()
{
    return engine_;
}

std::shared_ptr<StarSystem> Ship::getLocation()
{
    return location_;
}

std::string Ship::getName() const
{
    return name_;
}

void Ship::setName(std::string name)
{
    name_ = name;
}

void Ship::setLocation(std::shared_ptr<StarSystem> newLocation)
{
    auto oldLocation = location_;
    location_ = newLocation;

    if (events_)
    {
        events_->shipRelocated(shared_from_this(), oldLocation);
    }
}

void Ship::executeAction()
{
    if (!currentAction_)
    {
        return;
    }

    try
    {
        if (currentAction_->execute())
        {
            currentAction_ = nullptr;
        }
    }
    catch(GameException gexception)
    {
        currentAction_ = nullptr;

        if (events_)
        {
            events_->exceptionInExecution(shared_from_this(), gexception.msg());
        }
    }
}

void Ship::abandonShip()
{
    abandoned_ = true;
}

bool Ship::isAbandoned()
{
    return abandoned_;
}

}
