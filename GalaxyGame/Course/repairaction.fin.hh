#ifdef Finnish_dox

/**
 * @file repairaction.hh
 * @brief Moottorin korjaustoiminto.
 */

/**
  @namespace Common
*/

/**
 * @class Common::RepairAction : public IAction
 * @brief Alukset korjaavat moottoreita tällä toiminnolla.
 *
 * Korjaus voi viedä useamman vuoron, ja se saattaa vaatia tietynlaisen tähtijärjestelmän.
 */

//! Montako pykälää moottoria korjataan kunkin vuoron aikana.
//! @variable static const EngineHealth REPAIR_PER_INCREMENT;

/**
 * @fn Common::RepairAction::RepairAction(std::shared_ptr<Ship> executor, std::shared_ptr<ShipEngine> target, bool needsService);
 * @brief Rakentaja.
 * @post Toiminnolle on assosioitu toimintoa suorittava alus.
 * @param executor Toiminnon suorittava alus.
 * @param target Toiminnon kohteena oleva moottori.
 * @param needsService Oltava tosi, jos korjauksia ei pystytä suorittamaan ilman alusten sijainnista
 *                     löytyvää huoltoinfrastruktuuria.
 */

/**
 * @fn virtual bool Common::RepairAction::canDo() const;
 * @copydoc IAction::canDo()
 * @note RepairAction vaatii myös, että toiminnolla on jokin kohdealus ja että kohteella on rikkinäinen moottori.
 *       Mikäli korjaus vaatii huoltoinfrastruktuuria, sen on löydyttävä tähtijärjestelmästä.
 */

/**
 * @fn virtual bool Common::RepairAction::execute();
 * @copydoc IAction::execute()
 * @post Jos moottoria ei saatu vielä täyteen kuntoon, toimintoa ei ole suoritettu loppuun.
 */

/**
 * @private
*/
//! Toiminnon suorittava alus.
//! @variable std::shared_ptr<Ship> executor_;
//! Toiminnon kohteena oleva alus.
//! @variable std::shared_ptr<ShipEngine> target_;
//! Jos tosi, korjauksia ei pystytä suorittamaan ilman alusten sijainnista löytyvää huoltoinfrastruktuuria.
//! @variable bool needsService_;

#endif
// EOF: repairaction.fin.hh
