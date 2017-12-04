#ifndef STARSYSTEM_HH
#define STARSYSTEM_HH

#include "point.hh"

#include <memory>
#include <string>
#include <vector>
#include <list>

#ifdef English_dox
/**
 * @file starsystem.hh
 * @brief Starsystem is the basic unit for locations.
 */
#endif
namespace Common {

#ifdef English_dox
/**
 * @brief Galaxies are composed of star systems.
 *
 * StarSystem is a data class, which contains fields like coordinates, population, and economy type.
 * Many other thing in the game logic, like ship movement and cargo, rely on the star systems.
 */
#endif
class StarSystem
{
public:
    #ifdef English_dox
    /**
     * @brief StarSystem::Vector Type definition for vector that contains pointers to star systems.
     */
    #endif
    typedef std::vector<std::shared_ptr<StarSystem> > StarSystemVector;

    #ifdef English_dox
    /**
     * @brief If the population exceeds this treshold, a ship may repair without service.
     */
    #endif
    static const int POPULATION_REPAIR_TRESHOLD;

    #ifdef English_dox
    /**
     * @brief Type that denotes the economy practiced in a star system.
     */
    #endif
    enum ECONOMY_TYPE {
        Refinery,
        Extraction,
        HiTech,
        Industrial,
        Tourism,
        Agriculture,
        Service,
        Military,
        Terraforming,
        Colony,
        None
    };

    #ifdef English_dox
    /**
     * @brief A constructor.
     * @param name The name of the star system.
     * @param economy The main economy of the star system.
     * @param id The identifier of the star system.
     * @param population Population count of the star system.
     * @param location The location of the star system in coordinates.
     */
    #endif
    StarSystem(std::string name, ECONOMY_TYPE economy, unsigned id,
               uint64_t population, Point location);

    #ifdef English_dox
    /**
     * @return Name of the star system.
     * @post Exception guarantee: nothrow
     */
    #endif
    std::string getName() const;

    #ifdef English_dox
    /**
     * @return The main economy of the star system.
     * @post Exception guarantee: nothrow
     */
    #endif
    ECONOMY_TYPE getEconomy() const;

    #ifdef English_dox
    /**
     * @return Id of the star system.
     * @post Exception guarantee: nothrow
     */
    #endif
    unsigned getId() const;

    #ifdef English_dox
    /**
     * @return The population of the star system.
     * @post Exception guarantee: nothrow
     */
    #endif
    uint64_t getPopulation() const;

    #ifdef English_dox
    /**
     * @return The location of the star system in coordinates.
     * @post Exception guarantee: nothrow
     */
    #endif
    Point getCoordinates() const;

    #ifdef English_dox
    /**
     * @brief Checks if the star system inhabited.
     * @return True, if the star system inhabited, else false.
     * @post Exception guarantee: nothrow
     */
    #endif
    bool isInhabited() const;

    #ifdef English_dox
    /**
     * @brief Checks if it is possible to repair in the star system without service equipment.
     * @return True, if can, else false.
     * @post Exception guarantee: nothrow
     */
    #endif
    bool canRepair() const;

private:
    #ifdef English_dox
    //! The name of the star system.
    #endif
    std::string name_;
    #ifdef English_dox
    //! The main economy of the star system.
    #endif
    ECONOMY_TYPE economy_;
    #ifdef English_dox
    //! The dentifier of the star system.
    #endif
    unsigned id_;
    #ifdef English_dox
    //! Population count of the star system.
    #endif
    uint64_t population_;
    #ifdef English_dox
    //! The location of star system in coordinates.
    #endif
    Point coordinates_;
};

} //Common
#endif // STARSYSTEM_HH
