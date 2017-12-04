#ifndef ISTATISTICS_HH
#define ISTATISTICS_HH

#ifdef English_dox
/**
 *@file
 * @brief Defines the interface which keeps track of the game state.
 */
#endif
namespace Common {

#ifdef English_dox
/**
 * @brief Defines the interface for statistics class.
 *
 * @invariant getPoints() >= 0
 * @invariant getCreditBalance() >= MAX_LOAN_ALLOWANCE
 * MAX_LOAN_ALLOWANCE is the limit that the player is allowed to have debt.
 * The actual value is to be decided by the implementer of inherited class.
 */
#endif
class IStatistics
{
public:
#ifdef English_dox
    /**
     * @brief Default constructor for the interface (exists for the sake of documentation).
     */
#endif
    IStatistics() = default;

#ifdef English_dox
    /**
     * @brief Default destructor for the interface (needed since a base class should have a virtual destructor).
     */
#endif
    virtual ~IStatistics() = default;

#ifdef English_dox
    /**
     * @brief Increases the number of ships saved from distress.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void addSavedShip() = 0;

#ifdef English_dox
    /**
      * @return Returns the number of saved ships.
      * @post Exception guarantee: nothrow
      */
#endif
    virtual unsigned getSavedShips() const = 0;

#ifdef English_dox
    /**
     * @brief Increases the number of lost ships by one. Used to track also other removed ships.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void addLostShip() = 0;

#ifdef English_dox
    /**
     * @return The number of lost ships.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual unsigned getLostShips() const = 0;

#ifdef English_dox
    /**
     * @brief Increases the points of the player.
     * @param amount Points to be added.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void addPoints(unsigned amount) = 0;

#ifdef English_dox
    /**
     * @brief Reduces the points of the player.
     * @param amount Points to be reduced.
     * @exception StateException, if points would go under zero
     * @post Exception guarantee: strong
     */
#endif
    virtual void reducePoints(unsigned amount) = 0;

#ifdef English_dox
    /**
     * @return The total points of the player.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual unsigned getPoints() const = 0;

#ifdef English_dox
    /**
     * @brief Adds credits to the player's account.
     * @param amount Credits to be added
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void addCredits(unsigned amount) = 0;

#ifdef English_dox
    /**
     * @brief Reduces credits from the player's account.
     * @param amount Credits to be removed.
     * @exception StateException, if the invariant gets broken.
     * @post Exception guarantee: strong
     */
#endif
    virtual void reduceCredits(unsigned amount) = 0;

#ifdef English_dox
    /**
     * @return The number of credits left.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual int getCreditBalance() const = 0;
};

}//Common

#endif // ISTATISTICS_HH
