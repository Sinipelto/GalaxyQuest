#ifndef IEVENTHANDLER_HH
#define IEVENTHANDLER_HH

#include <string>
#include <memory>

#ifdef English_dox
/**
 * @file
 * @brief Defines the interface for handling events.
 */
#endif

namespace Common {

#ifdef English_dox
/**
 * @class Common::IEventHandler
 * @brief Event handler acts as an intermediary between objects that receives events and
 * the objects that are interested in those events. Objects spawn events by calling functions of
 * the event handler. See more details in the sequence diagrams within the course assignment.
 *
 * THUS, IN THIS CLASS THE DESCRIPTIONS OF THE FUNCTIONS ARE REALLY ABOUT
 * WHEN THE FUNCTION IS CALLED FROM OUTSIDE OF THE CLASS.
 *
 * In practise, event handler is used to notify the user interface about changes in
 * the game state.
 */
#endif

#ifdef English_dox
/**
 * Predefinition of necessary classes.
 */
#endif
class Ship;
class StarSystem;
struct Point;

class IEventHandler
{
public:
#ifdef English_dox
    /**
      * @brief Default constructor of interface (exists for the sake of documentation)
      */
#endif
    IEventHandler() = default;

 #ifdef English_dox
    /**
     * @brief Interface has a default constructor (exists as base class needs to have a virtual destructor)
     */
#endif
    virtual ~IEventHandler() = default;

#ifdef English_dox
    /**
     * @brief A new ship has been created in the galaxy.
     * @param ship The created ship
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void shipSpawned(std::shared_ptr<Ship> ship) = 0;

#ifdef English_dox
    /**
     * @brief A ship has been removed from the galaxy.
     * @param ship The removed ship
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void shipRemoved (std::shared_ptr<Ship> ship) = 0 ;

#ifdef English_dox
    /**
     * @brief A ship moved from one point to another.
     * @param ship The ship, which moved
     * @param origin The point, from which the ship moved
     * @param target The point, to which the ship moved
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void shipMoved(std::shared_ptr<Ship> ship, Point origin, Point target) = 0 ;

#ifdef English_dox
    /**
     * @brief A ship has moved to a star system, or moved away from a star system.
     * @param ship The ship, which relocated
     * @param starSystem The previous system where the ship was located. Can be nullptr.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void shipRelocated(std::shared_ptr<Ship> ship, std::shared_ptr<StarSystem> starSystem) = 0;

#ifdef English_dox
    /**
     * @brief An action executed by a ship caused an exception, and thus it was cancelled.
     * @param ship The ship that caused the exception.
     * @param msg Description of the exception.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void exceptionInExecution(std::shared_ptr<Ship> ship, std::string const& msg) = 0;

#ifdef English_dox
    /**
     * @brief A ship has switched on distress call.
     * @param ship The ship, which switched on the distress call
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void distressOn(std::shared_ptr<Ship> ship) = 0 ;

#ifdef English_dox
    /**
     * @brief A ship has switched off distress call.
     * @param ship The ship, which switched off the distress call
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void distressOff(std::shared_ptr<Ship> ship) = 0;

#ifdef English_dox
    /**
     * @brief A ship has been abandoned.
     * @param ship The ship, which has been abandoned
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void shipAbandoned(std::shared_ptr<Ship> ship) = 0;
};

}

#endif // IEVENTHANDLER_HH
