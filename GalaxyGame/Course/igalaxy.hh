#ifndef IGALAXY_HH
#define IGALAXY_HH

#include "ship.hh"
#include "starsystem.hh"

#include <memory>
#include <vector>
#ifdef English_dox
/**
 * @file
 * @brief Defines the interface for Galaxy.
 */
#endif

#ifdef English_dox
/**
 * @brief Pre-existing interfaces and classes that can be referred in code written by students.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Interface for Galaxy
 *
 *  @invariant Starsystems have unique name, id and location. Ship objects in a galaxy must be unique.
 */
#endif
class IGalaxy
{

public:
#ifdef English_dox
    /**
     * @brief IGalaxy::ShipVector Type definition for vector that contains pointers to ships.
     */
#endif
    typedef std::vector<std::shared_ptr<Common::Ship> > ShipVector;

#ifdef English_dox
    /**
     * @brief Default constructor for the interface (exists for the sake of documentation)
     * @post Galaxy is initialized and empty. Ships and star systems can be added to it.
     *
     */
#endif
    IGalaxy() = default;

#ifdef English_dox
    /**
     * @brief Default virtual destructor for the interface (exists, since base class needs to have a virtual destructor)
     */
#endif
    virtual ~IGalaxy() = default;

#ifdef English_dox
    /**
     * @brief addShip Adds a new ship to the galaxy
     * @param ship Ship to be added to the galaxy.
     * @post Ship is added to the galaxy.
     * @exception StateException If the galaxy contains the ship object already.
     * @post Exception guarantee: strong
     */
#endif
    virtual void addShip(std::shared_ptr<Ship> ship) = 0;

#ifdef English_dox
    /**
     * @brief removeShip removes a ship from the galaxy.
     * @param ship Ship to be removed
     * @post Ship is removed from the galaxy
     * @exception ObjectNotFoundException, if the ship does not exist
     * @post Exception guarantee: strong
     */
#endif
    virtual void removeShip(std::shared_ptr<Ship> ship) = 0;


#ifdef English_dox
    /**
     * @brief addStarSystem adds a new star system to the galaxy
     * @param system Star system to be added to the galaxy
     * @post Star system is added to the galaxy
     * @exception StateException, if a star system with the same name or id or location already exists in the galaxy
     * @post Exception guarantee: strong
     */
#endif
    virtual void addStarSystem(std::shared_ptr<StarSystem> system) = 0;

#ifdef English_dox
    /**
     * @brief getShips
     * @return Shared pointer to the vector containing ships in the galaxy. Empty vector, if there are no ships
     * @post Exception guarantee: nothrow
     */
#endif
    virtual std::shared_ptr<ShipVector> getShips() = 0;

#ifdef English_dox
    /**
     * @brief getSystemsInRange
     * @param origin Star system of interest
     * @param range Distance in light years
     * @exception Throws an ObjectNotFoundException, if the star system is not in the galaxy
     * @return Star systems that are within within the distance from the system of interest. Empty vector, if there are no such star systems
     * @post Exception guarantee: strong
     */
#endif
    virtual StarSystem::StarSystemVector getSystemsInRange(std::shared_ptr<StarSystem> origin, int range) = 0;

#ifdef English_dox
    /**
     * @brief getRandomSystem returns a random star system
     * @return A random star system from the set of star systems added to the galaxy
     * @exception ObjectNotFoundException, if the galaxy has no star systems
     * @post Exception guarantee: strong
     */
#endif
    virtual std::shared_ptr<StarSystem> getRandomSystem() = 0;

#ifdef English_dox
    /**
     * @brief getShipsInStarSystem
     * @param name Name of the star system
     * @return Returns vector of all ships in the star system. Empty vector, if there are no ships in the star system.
     * @exception ObjectNotFoundException, if the star system with given name does not exist
     * @post Exception guarantee: strong
     */
#endif
    virtual ShipVector getShipsInStarSystem(std::string name) = 0;

#ifdef English_dox
    /**
     * @brief getStarSystemByName gets the instance of a star system by name
     * @param name Name of the star system
     * @return Shared pointer to the object of the star system
     * @exception ObjectNotFoundException, if the star system with given name does not exist
     * @post Exception guarantee: strong
     */
#endif
    virtual std::shared_ptr<Common::StarSystem> getStarSystemByName(std::string name) = 0 ;

#ifdef English_dox
    /**
     * @brief getStarSystemById gets an instance of the star system by id
     * @param id Id of the star system
     * @return Shared pointer to the object of the star system
     * @exception ObjectNotFoundException, if the star system with given id does not exist
     * @post Exception guarantee: strong
     */
#endif
    virtual std::shared_ptr<Common::StarSystem> getStarSystemById(unsigned id) = 0;
};
} //Common

#endif // IGALAXY_HH
