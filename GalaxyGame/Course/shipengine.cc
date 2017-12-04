#include "shipengine.hh"
#include <cassert>

namespace Common {

ShipEngine::ShipEngine(int maxHealth) : maxHealth_(maxHealth), health_(maxHealth)
{
}

bool ShipEngine::canStart() const
{
    return !isBroken();
}

void ShipEngine::decreaseHealth(Health amountDecreased)
{
    health_ -= amountDecreased;

    if (health_ < 0)
    {
        health_ = 0;
    }
}

void ShipEngine::repair(Health amountRepaired)
{
    health_ += amountRepaired;

    if (health_ >= maxHealth_)
    {
        health_ = maxHealth_;
    }
}

ShipEngine::Health ShipEngine::getHealth() const
{
    return health_;
}

ShipEngine::Health ShipEngine::getMaxHealth() const
{
    return maxHealth_;
}

bool ShipEngine::isBroken() const
{
    return health_ <= 0;
}

}
