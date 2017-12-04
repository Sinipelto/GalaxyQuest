#include "shipfactory.hh"
#include <cassert>

namespace Course {

using Common::Ship;
using Common::StarSystem;
using Common::IEventHandler;
using std::shared_ptr;
using std::string;

ShipFactory &ShipFactory::getInstance()
{
    static ShipFactory instance;
    return instance;
}

ShipFactory::ShipFactory():
    buildableShips_(),
    shipNames()
{

}

void ShipFactory::addBuildableShip(const string typeName, BuildFunction buildFunction)
{
    ShipDefinition ship;
    ship.typeName = typeName;
    ship.buildFunction = buildFunction;
    buildableShips_.push_back(ship);
}

std::vector<std::string> ShipFactory::getBuildableShips() const
{
    std::vector<string> typeNames;
    for(auto definition: buildableShips_){
        typeNames.push_back(definition.typeName);
    }
    return typeNames;
}

shared_ptr<Ship> ShipFactory::createRandomShip(shared_ptr<StarSystem> initialLocation,
                                               shared_ptr<IEventHandler> handler)
{
    assert(handler);

    if (buildableShips_.size() < 1)
    {
        return nullptr;
    }
    auto chosen_ship = buildableShips_.at(Common::randomMinMax(0, buildableShips_.size() - 1));
    auto newShip = chosen_ship.buildFunction(initialLocation, handler);
    newShip->setName(shipNames.getRandomName());
    handler->shipSpawned(newShip);

    return newShip;
}

shared_ptr<Ship> ShipFactory::createShip(string typeName,
                                         shared_ptr<StarSystem> initialLocation,
                                         shared_ptr<IEventHandler> handler)
{
    shared_ptr<Ship> ship = nullptr;
    for(ShipDefinition definition : buildableShips_) {
        if(definition.typeName == typeName){
            ship = definition.buildFunction(initialLocation, handler);
            ship->setName(shipNames.getRandomName());
            handler->shipSpawned(ship);

        }
    }
    return ship;

}

} //Course
