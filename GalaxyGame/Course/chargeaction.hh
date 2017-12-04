#ifndef CHARGEACTION_HH
#define CHARGEACTION_HH
#include "iaction.hh"
#include "shipengine.hh"
#include <memory>

#ifdef English_dox
/**
 * @file
 * @brief Charge action of WormHoleDrive.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Ships can charge WormHoleDrive with this action
 *
 * The action is finished when engine is charged.
 */
#endif
class ChargeAction : public IAction
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @param engine Engine to be charged.
     */
#endif
    ChargeAction(std::shared_ptr<ShipEngine> engine);
#ifdef English_dox
    /**
     * @copydoc IAction::canDo()
     */
#endif
    bool canDo() const;
#ifdef English_dox
    /**
     * @copydoc IAction::execute()
     * @post If action is finished, engine has full charge.
     */
#endif
    bool execute();
private:
#ifdef English_dox
    //! Engine to be charged.
#endif
    std::shared_ptr<ShipEngine> engine_;
};

}//Common
#endif // CHARGEACTION_HH
