#ifndef UNLOADCARGO_HH
#define UNLOADCARGO_HH

#include "iaction.hh"
#include "cargoship.hh"

#ifdef English_dox
/**
 * @file unloadcargo.hh
 * @brief Action for unload cargo.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Cargo ships unload with this action.
 *
 * Cargo must be unloaded in such a star system, where it can be received.
 */
#endif

class UnloadCargo : public IAction
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @post Action is associated to a ship executing the action.
     * @param executor Ship executing the action.
     */
#endif
    UnloadCargo(std::shared_ptr<CargoShip> executor);
#ifdef English_dox
    /**
     * @note UnloadCargo requires also that there is cargo in the cargo hold of the executor, executor has a location,
     *       and the location can take cargo, i.e. there is someone living there and has economy.
     * @copydoc IAction::canDo()
     */
#endif
    virtual bool canDo() const;
#ifdef English_dox
    /**
     * @copydoc IAction::execute()
     * @post Executor has no cargo any more.
     */
#endif
    virtual bool execute();

private:
#ifdef English_dox
    //! Ship executing the action.
#endif
    std::shared_ptr<CargoShip> executor_;
};

}

#endif // UNLOADCARGO_HH
