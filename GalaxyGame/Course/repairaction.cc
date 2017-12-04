#include "repairaction.hh"
#include "gameexception.hh"

#include <cassert>

namespace Common {

const int RepairAction::REPAIR_PER_INCREMENT = 4;

RepairAction::RepairAction(std::shared_ptr<Ship> executor, std::shared_ptr<ShipEngine> target, bool needsService)
: executor_(executor), target_(target), needsService_(needsService)
{
}

bool RepairAction::canDo() const
{
    assert(executor_);

    if (!target_ || target_->getHealth() >= target_->getMaxHealth())
    {
        return false;
    }

    auto loc = executor_->getLocation();

    if (!loc)
    {
        return false;
    }

    if (needsService_ && !loc->canRepair())
    {
        return false;
    }

    return true;
}

bool RepairAction::execute()
{
    assert(executor_);

    if (!target_)
    {
        throw GameException("A RepairAction aborted: Targeted engine is missing.");
    }

    target_->repair(REPAIR_PER_INCREMENT);

    if (target_->getHealth() < target_->getMaxHealth())
    {
        return false;
    }

    return true;
}

}

