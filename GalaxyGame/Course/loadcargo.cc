#include "loadcargo.hh"

#include <cassert>

namespace Common {

LoadCargo::LoadCargo(std::shared_ptr<CargoShip> executor) : executor_(executor)
{

}

bool LoadCargo::canDo() const
{
    assert(executor_);

    if (executor_->getCargo() != StarSystem::None)
    {
        return false;
    }

    auto loc = executor_->getLocation();

    if (!loc || loc->getEconomy() == StarSystem::None || !loc->isInhabited())
    {
        return false;
    }

    return true;
}

bool LoadCargo::execute()
{
    assert(executor_);

    executor_->setCargo(executor_->getLocation()->getEconomy());

    return true;
}

}
