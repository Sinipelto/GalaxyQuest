#ifndef SHIPENGINE_HH
#define SHIPENGINE_HH

#include "starsystem.hh"

#ifdef English_dox
/**
 * @file shipengine.hh
 * @brief Abstract base class for ship engine.
 */
#endif
namespace Common {

#ifdef English_dox
/**
 * @brief The ship engine sets constrains on moving between star systems.
 *
 * Each derived class knows which star systems are accessible by the ship and how long the
 * trip lasts. Moreover, the base class implements the functions that affect the engine health.
 */
#endif
class ShipEngine
{
public:
    #ifdef English_dox
    /**
     * @brief The data type used to illustrate the engine health and changes to it.
     */
    #endif
    typedef int Health;

    #ifdef English_dox
    /**
     * @brief The constructor.
     * @param maxHealth The maximum health for the engine.
     */
    #endif
    ShipEngine(Health maxHealth);

    #ifdef English_dox
    /**
     * @brief The destructor.
     */
    #endif
    virtual ~ShipEngine() = default;

    #ifdef English_dox
    /**
     * @brief Checks if the engine can be started.
     * @post Exception guarantee: nothrow
     * @return True, if the engine can be started, else false.
     */
    #endif
    virtual bool canStart() const;

    #ifdef English_dox
    /**
     * @brief Executes things that happen on start.
     * @post Exception guarantee: basic
     */
    #endif
    virtual void onStart() =  0;

    #ifdef English_dox
    /**
     * @brief Gets all star systems accessible by the engine.
     * @pre Parameter source must not be nullptr.
     * @post Exception guarantee: nothrow
     * @param source The possible origin of a trip.
     * @return Possible destinations of a trip. Must not contain parameter source.
     */
    #endif
    virtual StarSystem::StarSystemVector getValidDestinations(std::shared_ptr<StarSystem> source) const = 0;

    #ifdef English_dox
    /**
     * @brief Checks that it is possible to traverse between two systems in one trip.
     *        Typically the source cannot be the same as the destination.
     * @pre Parameter source must not be nullptr.
     * @pre Parameter destination must not be nullptr.
     * @post Exception guarantee: nothrow
     * @param source The origin of the proposed trip.
     * @param destination The destination of the proposed trip.
     * @return True, if the trip is possible. False, if not.
     */
    #endif
    virtual bool isValidTrip(std::shared_ptr<StarSystem> source,
                                std::shared_ptr<StarSystem> destination) const =  0;

    #ifdef English_dox
    /**
     * @brief Calculates how many turns of movement are needed for a trip between
     *        two systems.
     * @pre Parameter source must not be nullptr.
     * @pre Parameter destination must not be nullptr.
     * @post Exception guarantee: nothrow
     * @param source The origin of the proposed trip.
     * @param destination The destination of the proposed trip.
     * @return How many turns it takes.
     */
    #endif
    virtual int requiredTurns(std::shared_ptr<StarSystem> source,
                             std::shared_ptr<StarSystem> destination) const =  0;

    #ifdef English_dox
    /**
     * @brief Decreases the engine health.
     * @post If the engine broke, an event is spawned.
     * @post Exception guarantee: nothrow
     * @param amountDecreased How much the health is decreased.
     */
    #endif
    void decreaseHealth(Health amountDecreased);

    #ifdef English_dox
    /**
     * @brief Increases the engine health.
     * @post Exception guarantee: nothrow
     * @param amountRepaired How much the health is increased.
     */
    #endif
    void repair(Health amountRepaired);

    #ifdef English_dox
    /**
     * @brief Checks the current engine health.
     * @post Exception guarantee: nothrow
     * @return The current engine health.
     */
    #endif
    Health getHealth() const;

    #ifdef English_dox
    /**
     * @brief Checks the maximum possible health for the engine.
     * @post Exception guarantee: nothrow
     * @return The maximum engine health.
     */
    #endif
    Health getMaxHealth() const;

    #ifdef English_dox
    /**
     * @brief Checks if the engine is broken.
     * @post Exception guarantee: nothrow
     * @return True, if the engine is broken. False, if not.
     */
    #endif
    bool isBroken() const;

private:
    #ifdef English_dox
    //! The maximum health of the engine.
    #endif
    Health maxHealth_;
    #ifdef English_dox
    //! The current health of the engine.
    #endif
    Health health_;
};
} //Common

#endif // SHIPENGINE_HH
