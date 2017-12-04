#include "gamerunner.hh"
#include "iaction.hh"
#include "shipfactory.hh"

#include <list>
#include <cassert>

namespace Course {

GameRunner::GameRunner(std::shared_ptr<Common::IGalaxy> galaxy,
                       std::shared_ptr<Common::IEventHandler> events)
    : galaxy_(galaxy), events_(events)
{

}

void GameRunner::spawnShips(unsigned int count)
{
    assert(galaxy_);

    auto factory = ShipFactory::getInstance();

    for (unsigned int i = 0; i < count; ++i)
    {
        auto newShip = factory.createRandomShip(galaxy_->getRandomSystem(), events_);

        galaxy_->addShip(newShip);
    }
}

void GameRunner::createActions()
{
    assert(galaxy_);

    auto ships = galaxy_->getShips();
    auto shipsEnd = ships->end();

    for (auto shipIter = ships->begin(); shipIter != shipsEnd; ++shipIter)
    {
        auto ship = *shipIter;

        ship->decideAction();
    }
}

void GameRunner::doActions()
{
    assert(galaxy_);

    auto ships = galaxy_->getShips();
    auto end = ships->end();

    for (auto iter = ships->begin(); iter != end; ++iter)
    {
        auto ship = *iter;
        ship->executeAction();
    }
}

}
