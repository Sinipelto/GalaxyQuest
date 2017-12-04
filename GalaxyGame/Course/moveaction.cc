#include "moveaction.hh"
#include "shipengine.hh"
#include "utility.hh"
#include "gameexception.hh"

#include <cassert>
#include <cmath>

namespace Common {

MoveAction::MoveAction(std::shared_ptr<Ship> executor, std::shared_ptr<StarSystem> destination,
                       std::shared_ptr<IEventHandler> events)
    : executor_(executor), destination_(destination), events_(events), travelling_(false), turns_(0),
      requiredTurns_(0), x_pos_(0), y_pos_(0), x_diff_(0), y_diff_(0)
{
}

bool MoveAction::canDo() const
{
    assert(executor_);

    auto currentLocation = executor_->getLocation();

    if (!currentLocation || !destination_)
    {
        return false;
    }

    auto engine = executor_->getEngine();

    if (!engine || !engine->canStart())
    {
        return false;
    }

    if (!engine->isValidTrip(currentLocation, destination_))
    {
        return false;
    }

    return true;
}

bool MoveAction::execute()
{
    assert(executor_);

    if (!travelling_)
    {
        startTrip();
    }

    ++turns_;

    auto origin = Point(round(x_pos_), round(y_pos_));
    x_pos_ += x_diff_;
    y_pos_ += y_diff_;

    if (events_)
    {
        auto target = Point(round(x_pos_),round(y_pos_));
        events_->shipMoved(executor_, origin, target);
    }

    if (concludeTrip())
    {
        return true;
    }

    return false;
}

void MoveAction::startTrip()
{
    assert(!travelling_);

    auto currentLocation = executor_->getLocation();

    if (!currentLocation)
    {
        throw GameException("A MoveAction aborted: Executing ship was missigng its"
                            " origin location before starting the trip.");
    }

    auto engine = executor_->getEngine();

    if (!engine)
    {
        throw GameException("A MoveAction aborted: Executing ship is missing the engine.");
    }

    engine->onStart();

    requiredTurns_ = engine->requiredTurns(currentLocation, destination_);

    auto from = currentLocation->getCoordinates();
    auto to = destination_->getCoordinates();

    x_pos_ = from.x;
    y_pos_ = from.y;

    x_diff_ = (double)(to.x - from.x)/(double)requiredTurns_;
    y_diff_ = (double)(to.y - from.y)/(double)requiredTurns_;

    travelling_ = true;
    executor_->setLocation(NULL);
}

bool MoveAction::concludeTrip()
{
    if (turns_ >=requiredTurns_)
    {
        executor_->setLocation(destination_);
        travelling_ = false;
        assert(executor_->getLocation());
        return true;
    }

    return false;
}

}
