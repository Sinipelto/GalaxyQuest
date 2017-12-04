#include "chargeaction.hh"
#include "wormholedrive.hh"
namespace Common {


ChargeAction::ChargeAction(std::shared_ptr<Common::ShipEngine> engine):
    engine_(engine)
{

}

bool ChargeAction::canDo() const
{
    std::shared_ptr<WormHoleDrive> ptr = std::dynamic_pointer_cast<WormHoleDrive> (engine_);
    return ptr != nullptr &&!ptr->isCharged();
}

bool ChargeAction::execute()
{
    std::shared_ptr<WormHoleDrive> wormHoleDrive = std::dynamic_pointer_cast<WormHoleDrive> (engine_);
    wormHoleDrive->charge();
    return wormHoleDrive->isCharged();
}
}//Common
