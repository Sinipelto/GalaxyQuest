#include "unloadcargo.hh"

#include <cassert>

namespace Common {

UnloadCargo::UnloadCargo(std::shared_ptr<CargoShip> executor) : executor_(executor)
{

}

bool UnloadCargo::canDo() const
{
    assert(executor_);

    if (executor_->getCargo() == StarSystem::None)
    {
        return false;
    }

    auto loc = executor_->getLocation();

    if (!loc || loc->getEconomy() == executor_->getCargo())
    {
        return false;
    }

    if (!loc->isInhabited() || loc->getEconomy() == StarSystem::None)
    {
        return false;
    }

    return true;
}

bool UnloadCargo::execute()
{
    assert(executor_);

    executor_->setCargo(StarSystem::None);

    return true;
}

}
