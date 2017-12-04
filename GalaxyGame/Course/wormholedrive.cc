#include "wormholedrive.hh"
#include <cassert>

namespace Common {

const int WormHoleDrive::RANGE = 60;
const int WormHoleDrive::MAX_DAMAGE_PER_START = 5;
const int WormHoleDrive::MIN_DAMAGE_PER_START = 1;
const int WormHoleDrive::MAX_HEALTH = 25;
const int WormHoleDrive::MAX_CHARGE = 5;

WormHoleDrive::WormHoleDrive(std::shared_ptr<IGalaxy> galaxy)
    : ShipEngine(MAX_HEALTH), galaxy_(galaxy), charge_(MAX_CHARGE)
{
}

bool WormHoleDrive::canStart() const
{
    return isCharged() && ShipEngine::canStart();
}

void WormHoleDrive::onStart()
{
    decreaseHealth(Common::randomMinMax(MIN_DAMAGE_PER_START, MAX_DAMAGE_PER_START));

    charge_ -= MAX_CHARGE;
}

StarSystem::StarSystemVector WormHoleDrive::getValidDestinations(std::shared_ptr<StarSystem> source) const
{
    assert(source && "WORMHOLEDRIVE: No source given for valid destination query.");

    if (!galaxy_)
    {
        return StarSystem::StarSystemVector();
    }

    return galaxy_->getSystemsInRange(source, RANGE);
}

bool WormHoleDrive::isValidTrip(std::shared_ptr<StarSystem> source,
                            std::shared_ptr<StarSystem> destination) const
{
    assert(source && "WORMHOLEDRIVE: No source given for valid trip query.");
    assert(destination && "WORMHOLEDRIVE: No destination given for valid trip query.");

    double distance = destination->getCoordinates().distanceTo(source->getCoordinates());

    return distance <= RANGE;
}

int WormHoleDrive::requiredTurns(std::shared_ptr<StarSystem> /*source*/,
                         std::shared_ptr<StarSystem> /*destination*/) const
{
    return 1;
}

void WormHoleDrive::charge()
{
    ++charge_;
}

bool WormHoleDrive::isCharged() const
{
    return charge_ >= MAX_CHARGE;
}

}//Common
