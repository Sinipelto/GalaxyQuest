#include "warpdrive.hh"
#include <cassert>
#include <cmath>

namespace Common {

const int WarpDrive::RANGE = 60;
const int WarpDrive::DISTANCE_PER_MOVEMENT = 5;
const int WarpDrive::MAX_DAMAGE_PER_START = 3;
const int WarpDrive::MIN_DAMAGE_PER_START = 0;
const int WarpDrive::MAX_HEALTH = 15;

WarpDrive::WarpDrive(std::shared_ptr<IGalaxy> galaxy)
    : ShipEngine(MAX_HEALTH), galaxy_(galaxy)
{
}

void WarpDrive::onStart()
{
    decreaseHealth(Common::randomMinMax(MIN_DAMAGE_PER_START, MAX_DAMAGE_PER_START));
}

StarSystem::StarSystemVector WarpDrive::getValidDestinations(std::shared_ptr<StarSystem> source) const
{
    assert(source && "WARPENGINE: No source given for valid destination query.");

    if (!galaxy_)
    {
        return StarSystem::StarSystemVector();
    }

    return galaxy_->getSystemsInRange(source, RANGE);
}

bool WarpDrive::isValidTrip(std::shared_ptr<StarSystem> source,
                            std::shared_ptr<StarSystem> destination) const
{
    assert(source && "WARPENGINE: No source given for valid trip query.");
    assert(destination && "WARPENGINE: No destination given for valid trip query.");

    double distance = destination->getCoordinates().distanceTo(source->getCoordinates());

    return distance <= RANGE;
}

int WarpDrive::requiredTurns(std::shared_ptr<StarSystem> source,
                         std::shared_ptr<StarSystem> destination) const
{
    assert(DISTANCE_PER_MOVEMENT > 0);

    double distance = destination->getCoordinates().distanceTo(source->getCoordinates());

    double requiredTurns = distance/DISTANCE_PER_MOVEMENT;

    return ceil(requiredTurns);
}

}
