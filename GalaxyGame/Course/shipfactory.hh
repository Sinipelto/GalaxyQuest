#ifndef SHIPFACTORY_HH
#define SHIPFACTORY_HH
#include "ship.hh"
#include "shipnamegenerator.hh"
#include <functional>
#include <memory>
#include <string>
#include <vector>

#ifdef English_dox
/**
 * @file shipfactory.hh
 * @brief Singleton class that creates ships.
 */
#endif
namespace Course {

#ifdef English_dox
/**
 * @brief Singleton class for creating ships.
 *
 * One may register new ships using function addBuildableShip.
 * Examples can be found in module Initialize at function getGameRunner.
 */
#endif
class ShipFactory
{
public:
    #ifdef English_dox
    /**
     * @brief BuildFunction type definition for the function used to create ships.
     */
    #endif
    typedef std::function<std::shared_ptr<Common::Ship>(std::shared_ptr<Common::StarSystem>,
                                                        std::shared_ptr<Common::IEventHandler>)> BuildFunction;
    #ifdef English_dox
    /**
     * @post Exception guarantee: nothrow
     * @return A reference to the factory.
     */
    #endif
    static ShipFactory& getInstance();
    #ifdef English_dox
    /**
     * @brief Registers a new ship type available for building.
     * @param typeName The identifier for the buildable ship type.
     * @param buildFunction The function for building a ship of the type.
     * @post Exception guarantee: basic
     */
    #endif
    void addBuildableShip(const std::string typeName, BuildFunction buildFunction);
    #ifdef English_dox
    /**
     * @post Exception guarantee: nothrow
     * @return The type names of the buildable ships.
     */
    #endif
    std::vector<std::string> getBuildableShips() const;
    #ifdef English_dox
    /**
     * @brief Builds a ship, which type is randomly picked from registered ship types.
     * @param initialLocation The star system where the ship will be initially located after build.
     * @param handler The ship will be associated with this event handler.
     * @post Spawns event about building of the ship, using parameter handler.
     * @post Exception guarantee: nothrow
     * @return The built ship. Will be nullptr, if no ships were registered.
     */
    #endif
    std::shared_ptr<Common::Ship> createRandomShip(std::shared_ptr<Common::StarSystem> initialLocation,
                                                   std::shared_ptr<Common::IEventHandler> handler);
    #ifdef English_dox
    /**
     * @brief Builds a ship which type corresponds parameter typeName
     * @param typeName The identifier of the ship type that will be built.
     * @param initialLocation the star system where the ship will be initially located after build
     * @param handler The ship will be associated with this event handler.
     * @post Spawns event about building of the ship, using parameter handler.
     * @post Exception guarantee: nothrow
     * @return The built ship. Will be nullptr, if no ships were registered with parameter typeName.
     */
    #endif
    std::shared_ptr<Common::Ship> createShip(std::string typeName,
                                             std::shared_ptr<Common::StarSystem> initialLocation,
                                             std::shared_ptr<Common::IEventHandler> handler);
private:
    ShipFactory();
    struct ShipDefinition {
        std::string typeName;
        BuildFunction buildFunction;
    };
    std::vector< ShipDefinition > buildableShips_;
    ShipNameGenerator shipNames;

};

} //Course
#endif // SHIPFACTORY_HH
