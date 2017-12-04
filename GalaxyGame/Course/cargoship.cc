#include "cargoship.hh"

#include "moveaction.hh"
#include "repairaction.hh"
#include "unloadcargo.hh"
#include "loadcargo.hh"
#include "distressaction.hh"
#include "chargeaction.hh"

namespace Common {

CargoShip::CargoShip(std::shared_ptr<ShipEngine> engine,
                     std::shared_ptr<StarSystem> initialLocation,
                     std::shared_ptr<IEventHandler> events)
    : Ship(engine, initialLocation, events),
      cargo_(StarSystem::None)
{

}

bool CargoShip::decideAction()
{
    if (isAbandoned()){
        return false;
    }
    if (currentAction_)
    {
        return false;
    }

    auto shared_ship = std::static_pointer_cast<CargoShip>(shared_from_this());
    auto ulg = std::make_shared<UnloadCargo>(shared_ship);

    if (ulg->canDo())
    {
        currentAction_ = ulg;
        return true;
    }

    auto lg = std::make_shared<LoadCargo>(shared_ship);

    if (lg->canDo())
    {
        currentAction_ = lg;
        return true;
    }

    if (decideToMove())
    {
        return true;
    }
    auto charge = std::make_shared<ChargeAction>(engine_);
    if(charge->canDo()){
        currentAction_ = charge;
        return true;
    }

    auto ra = std::make_shared<RepairAction>(shared_from_this(), engine_, true);

    if (ra->canDo())
    {
        currentAction_ = ra;
        return true;
    }

    auto da = std::make_shared<DistressAction>(shared_from_this(), events_);

    if (da->canDo())
    {
        currentAction_ = da;
        return true;
    }

    return false;
}

StarSystem::ECONOMY_TYPE CargoShip::getCargo() const
{
    return cargo_;
}

void CargoShip::setCargo(StarSystem::ECONOMY_TYPE cargo)
{
    cargo_ = cargo;
}

bool CargoShip::decideToMove()
{
    if (!engine_)
    {
        return true;
    }

    auto systems = engine_->getValidDestinations(location_);

    if (systems.size() < 1)
    {
        return false;
    }

    int chosen_index = randomMinMax(0, systems.size() - 1);
    auto chosen_location = systems.at(chosen_index);

    auto ma = std::make_shared<MoveAction>(shared_from_this(), chosen_location, events_);

    if (ma->canDo())
    {
        currentAction_ = ma;
        return true;
    }

    return false;
}

std::shared_ptr<IAction> CargoShip::getAction() const
{
    return currentAction_;
}

}
