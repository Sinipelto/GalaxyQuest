#ifndef LOADCARGO_HH
#define LOADCARGO_HH

#include "iaction.hh"
#include "cargoship.hh"

#ifdef English_dox
/**
 * @file
 * @brief Load action.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Cargo ships load their cargo with this action.
 *
 * Cargo must be loaded in such a star system that can give load.
 */
#endif
class LoadCargo : public IAction
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @post Action is associated with the ship executing the action.
     * @param executor Ship executing the action.
     */
#endif
    LoadCargo(std::shared_ptr<CargoShip> executor);
#ifdef English_dox
    /**
     * @copydoc IAction::canDo()
     * @note LoadCargo requires also that the cargo hold of the executor is empty, executor has a location,
     *       and the location can give load, i.e. someone lives there and there is economy.
     */
#endif
    virtual bool canDo() const;
#ifdef English_dox
    /**
     * @copydoc IAction::execute()
     * @post The executor has loaded cargo, which is of the economy type of the star system.
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

#endif // LOADCARGO_HH
