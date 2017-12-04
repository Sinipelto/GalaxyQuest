#ifdef Finnish_dox

/**
  @include
#include "iaction.hh"
#include "shipengine.hh"
#include <memory>
*/

/**
 * @file chargeaction.hh
 * @brief Madonreikämoottorin lataustoiminto.
 */

/**
  @namespace Common
*/

/**
 * @class Common::ChargeAction : public IAction
 * @brief Alukset voivat ladata madonreikämoottorin tämän toiminnon avulla
 *
 * Toiminto kestää kunnes moottori on ladattu.
 */

/**
  * @fn Common::ChargeAction::ChargeAction(std::shared_ptr<ShipEngine> engine);
  * @brief Rakentaja.
  * @param engine Ladattava mooottori.
  */

/**
  * @fn bool Common::ChargeAction::canDo() const;
  * @copydoc IAction::canDo()
  */

/**
  * @fn bool Common::ChargeAction::execute();
  * @copydoc IAction::execute()
  * @post Jos toiminto saatiin suoritettua loppuun, moottori on täydessä latauksessa.
  */

/**
  * @private
  */

    //! Ladattava moottori.
    //! @variable std::shared_ptr<ShipEngine> engine_;

#endif
// EOF: chargeaction.fin.hh
