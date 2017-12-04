#include "distressaction.hh"
#include "gameexception.hh"

#include <cassert>

namespace Common {

unsigned const DistressAction::MAX_DISTRESS_DURATION = 20;

DistressAction::DistressAction(std::shared_ptr<Ship> executor, std::shared_ptr<IEventHandler> events)
    : executor_(executor),
      events_(events),
      distressAsserted_(false),
      distressDuration_(0)
{

}

bool DistressAction::canDo() const
{
    assert(executor_);
    auto engine = executor_->getEngine();
    if (!engine || !engine->isBroken())
    {
        return false;
    }

    return true;
}

bool DistressAction::execute()
{
    assert(executor_);
    if (!distressAsserted_ && events_)
    {
        events_->distressOn(executor_);
        distressAsserted_ = true;
    }
    auto engine = executor_->getEngine();

    if (!engine)
    {
        throw GameException("A DistressAction aborted: Executing ship is missing the engine.");
    }
    if(engine->isBroken()){
        ++distressDuration_;
    }
    if(distressDuration_ >= MAX_DISTRESS_DURATION){
        events_->shipAbandoned(executor_);
        executor_->abandonShip();
        return true;
    }

    if (engine->getHealth() < engine->getMaxHealth())
    {
        return false;
    }

    if (events_)
    {
        events_->distressOff(executor_);
    }

    return true;
}

}
