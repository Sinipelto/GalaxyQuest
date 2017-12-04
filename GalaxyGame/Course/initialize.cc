#include "initialize.hh"
#include "starsystem.hh"
#include "starsystemfactory.hh"
#include "shipfactory.hh"
#include "ship.hh"
#include "cargoship.hh"
#include "warpdrive.hh"
#include "wormholedrive.hh"
#include "gamerunner.hh"
#include "stateexception.hh"
#include "QDebug"
namespace Common {

std::shared_ptr<IGameRunner> getGameRunner(std::shared_ptr<IGalaxy> galaxy,
                                           std::shared_ptr<IEventHandler> handler)
{
    Course::StarSystemFactory::getInstance().readJSON("starsystems.json");
    std::shared_ptr <Course::GameRunner> runner = std::make_shared<Course::GameRunner>(galaxy, handler);
    auto starSystems = Course::StarSystemFactory::getInstance().getAllStarSystems();
    for (auto starSystem = starSystems.begin(); starSystem != starSystems.end(); starSystem++) {
        try{
            galaxy->addStarSystem(*starSystem);
        }
        catch (Common::StateException e){
           qDebug() << "Caught StateException when adding star system:" << QString::fromStdString(e.msg());
        }
    }
    Course::ShipFactory::getInstance().addBuildableShip("CargoShip",
                                                        [=] (std::shared_ptr<Common::StarSystem> initialLocation,
                                                        std::shared_ptr<IEventHandler> events
                                                        ) -> std::shared_ptr<Common::Ship>  {
        return std::make_shared<Common::CargoShip>(std::make_shared<Common::WarpDrive>(galaxy), initialLocation, events);
    }
    );
    Course::ShipFactory::getInstance().addBuildableShip("WormHoleCargoShip",
                                                        [=] (std::shared_ptr<Common::StarSystem> initialLocation,
                                                        std::shared_ptr<IEventHandler> events
                                                        ) -> std::shared_ptr<Common::Ship>  {
        return std::make_shared<Common::CargoShip>(std::make_shared<Common::WormHoleDrive>(galaxy), initialLocation, events);
    }
    );

    return runner;
}

void addNewShipType(std::string typeName, BuildFunction buildFunction)
{
    Course::ShipFactory::getInstance().addBuildableShip(typeName, buildFunction);
}

} //Common
