#ifndef IGAMERUNNER_HH
#define IGAMERUNNER_HH
#ifdef English_dox


/**
 * @file
 * @brief Interface class that is used to control the flow of the game
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Offers an interface, which is used to control the game logic
 *
 * The functionality is divided to three parts: spawning new ships, deciding actions for ships,
 * and performing the actions of ships
 */
#endif

class IGameRunner
{

public:
#ifdef English_dox
    /**
     * @brief Constructor, exists solely for documentation
     */
#endif
    IGameRunner() = default;
#ifdef English_dox
    /**
     * @brief Virtual destructor. Does nothing, since this is an interface class
     */
#endif
    virtual ~IGameRunner() = default;
#ifdef English_dox
    /**
     * @brief Creates given number of randomized ships and gives them to the associated galaxy
     * @pre A galaxy has been associated with this object
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void spawnShips(unsigned int count) = 0;
#ifdef English_dox
    /**
     * @brief Tries to set an action to all such NPC ships in the associated galaxy that are missing
     *        an action.
     * @pre A galaxy has been associated with this object
     * @post All NPC ships have actions, except for those that an action could not be set.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void createActions() = 0;
#ifdef English_dox
    /**
     * @brief Encourages all ships in the associated galaxy to perform their actions.
     * @pre A galaxy has been associated with this object
     * @post Exception guarantee: nothrow
     */
#endif
    virtual void doActions() = 0;
};
} //Common

#endif // IGAMERUNNER_HH
