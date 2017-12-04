#ifndef IACTION_HH
#define IACTION_HH

#ifdef English_dox
/**
 * @file
 * @brief Interface class for all actions
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Interface class, which all actions must be inherited from.
 *
 * Actions are divided into three parts: The constructor of an inherited class gets those variables as parameters
 * that are needed in the action. Method canDo() checks, if the action can be executed with the given
 * parameters. Method execute() executes the action, but it may fail.
 * Some actions may take multiple turns. In these cases method execute() does not finish the action at one call.
 */
#endif
class IAction
{
public:
#ifdef English_dox
    /**
     * @brief Constructor, exists solely for documentation
     */
#endif
    IAction() = default;
#ifdef English_dox

    /**
     * @brief Virtual destructor. Does nothing, since this is an interface class
     */
#endif
    virtual ~IAction() = default;
#ifdef English_dox

    /**
     * @brief Checks, if action exection can be started.
     *        Does not speak out, if already started action can be continued.
     * @pre A ship performing the action has been associated with the action
     * @post Exception guarantee: nothrow
     * @return True, if the action execution can be started. Otherwise false.
     */
#endif
    virtual bool canDo() const = 0;
#ifdef English_dox

    /**
     * @brief Tries to execute the action or at least advances the execution.
     * @pre A ship performing the action has been associated with the action
     * @exception GameException If the things needed in the action are in such a state
     *         that the action cannot be executed anymore.
     * @return True, if the action was finished. False, if the action was not finished.
     * @post Exception guarantee: basic
     */
#endif
    virtual bool execute() = 0;
};

}

#endif // IACTION_HH
