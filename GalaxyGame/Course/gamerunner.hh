#ifndef GAMERUNNER_HH
#define GAMERUNNER_HH

#include "igamerunner.hh"
#include "igalaxy.hh"

#ifdef English_dox
/**
 * @file gamerunner.hh
 * @brief Implements interface IGamerunner.
 */
#endif

#ifdef English_dox
/**
 * @brief Contains pre-existing classes that may not be referred by code written by students.
 */
#endif
namespace Course {

#ifdef English_dox
/**
 * @brief Implements the interface IGamerunner.
 *
 * Functionality is practically the same as defined in interface IGameRunner.
 * Constructor however needs more arguments.
 */
#endif
class GameRunner : public Common::IGameRunner
{
public:

#ifdef English_dox
    /**
     * @brief Constructor.
     * @post Object is associated with the galaxy.
     * @param galaxy Galaxy, to which this object has to be associated.
     * @param events Initial events are spawned using this. Possibly nullptr.
     */
#endif
    GameRunner(std::shared_ptr<Common::IGalaxy> galaxy,
               std::shared_ptr<Common::IEventHandler> events);

#ifdef English_dox
    /**
     * @copydoc igamerunner::spawnShips()
     */
#endif
    virtual void spawnShips(unsigned int count);

#ifdef English_dox
    /**
     * @copydoc igamerunner::createActions()
     */
#endif
    virtual void createActions();

#ifdef English_dox
    /**
     * @copydoc igamerunner::doActions()
     */
#endif
    virtual void doActions();

private:
    //! Galaxy, which this object is associated with.
    std::shared_ptr<Common::IGalaxy> galaxy_;
    //! Events are spawned using this.
    std::shared_ptr<Common::IEventHandler> events_;
};

}

#endif // GAMERUNNER_HH
