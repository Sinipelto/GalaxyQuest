#ifndef ISHIP_HH
#define ISHIP_HH

#include <memory>

#include "shipengine.hh"
#include "starsystem.hh"
#include "ieventhandler.hh"

#ifdef English_dox
/**
 * @file ship.hh
 * @brief Abstract base class for ship.
 */
#endif
namespace Common {

class IAction;

#ifdef English_dox
/**
 * @brief Abstract base class, which all ship types must be derived from.
 *
 * The most vital features of ship are executing an action and deciding the next action.
 * Deciding the next action must be implemented in the derived class.
 */
#endif
class Ship : public std::enable_shared_from_this<Ship>
{

public:
    #ifdef English_dox
    /**
     * @brief Constructor.
     * @param engine The engine which is utilized by the ship.
     * @param initialLocation The location where the ship is spawned.
     * @param events This is used to spawn events from the ship. Can be nullptr.
     */
    #endif
    Ship(std::shared_ptr<ShipEngine> engine,
         std::shared_ptr<StarSystem> initialLocation,
         std::shared_ptr<IEventHandler> events);

    #ifdef English_dox
    /**
     * @brief Destructor.
     */
    #endif
    virtual ~Ship() = default;

    #ifdef English_dox
    /**
     * @post Exception guarantee: nothrow
     * @return The engine which is utilized by the ship.
     */
    #endif
    virtual std::shared_ptr<ShipEngine> getEngine();

    #ifdef English_dox
    /**
     * @post Exception guarantee: nothrow
     * @return The current location of the ship. Nullptr, if the ship is moving between systems.
     */
    #endif
    virtual std::shared_ptr<StarSystem> getLocation();

    #ifdef English_dox
    /**
     * @post Exception guarantee: nothrow
     * @return The name of the ship.
     */
    #endif
    virtual std::string getName() const;

    #ifdef English_dox
    /**
     * @brief Sets the name of the ship.
     * @post A name is set for the ship.
     * @post Exception guarantee: strong
     * @param name The new name of the ship.
     */
    #endif
    virtual void setName(std::string name);

    #ifdef English_dox
    /**
     * @brief Sets a new location for the ship.
     * @post The location of the ship has changed and it has spawned an event.
     * @post Exception guarantee: basic
     * @param newLocation The new location of the ship. Can be nullptr.
     */
    #endif
    virtual void setLocation(std::shared_ptr<StarSystem> newLocation);

    #ifdef English_dox
    /**
     * @brief Executes the current action of the ship, or proceeds in it.
     *        But only if the ship has an action.
     * @post Exception guarantee: nothrow
     * @post If the execution was completed, the ship has no current action.
     */
    #endif
    virtual void executeAction();

    #ifdef English_dox
    /**
     * @brief Flags the ship as abandoned.
     * @post Exception guarantee: basic
     * @post The ship is abandoned, and thus cannot choose an action nor can be repaired.
     */
    #endif
    virtual void abandonShip();
    
    #ifdef English_dox
    /**
     * @brief Checks if the ship is abandoned.
     * @post Exception guarantee: basic
     * @return True, if the ship is abandoned, else false.
     */
    #endif
    virtual bool isAbandoned();

    #ifdef English_dox
    /**
     * @brief Instructs the ship to decide a new action. Does nothing, if
     *        the ships already has an action.
     * @post The ship has a new action, if it could be created and executed.
     * @post Exception guarantee: nothrow
     * @return True, if a new action was created, else false.
     */
    #endif
    virtual bool decideAction() = 0;

protected:
    #ifdef English_dox
    //! The engine of the ship.
    #endif
    std::shared_ptr<ShipEngine> engine_;
    #ifdef English_dox
    //! The current location of the ship.
    #endif
    std::shared_ptr<StarSystem> location_;
    #ifdef English_dox
    //! This is used to spawn events by the ship.
    #endif
    std::shared_ptr<IEventHandler> events_;
    #ifdef English_dox
    //! The current action of the ship, either in execution or waiting for execution.
    #endif
    std::shared_ptr<IAction> currentAction_;
    #ifdef English_dox
    //! The name of the ship.
    #endif
    std::string name_;
    #ifdef English_dox
    //! True, if ship is abandoned, else false.
    #endif
    bool abandoned_;
};

} //Common

#endif // ISHIP_HH
