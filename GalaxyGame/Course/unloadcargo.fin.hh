#ifdef Finnish_dox

/**
 * @file unloadcargo.hh
 * @brief Lastinpurkutoiminto.
 */
/**
  @namespace Common
*/

/**
 * @class Common::UnloadCargo : public IAction
 * @brief Rahtialukset purkavat lastinsa tällä toiminnolla.
 *
 * Lasti pitää purkaa sellaisessa tähtijärjestelmässä, jossa se voidaan vastaanottaa.
 */

/**
 * @fn Common::UnloadCargo::UnloadCargo(std::shared_ptr<CargoShip> executor);
 * @brief Rakentaja.
 * @post Toiminnolle on assosioitu toimintoa suorittava alus.
 * @param executor Toiminnon suorittava alus.
 */

/**
 * @fn virtual bool Common::UnloadCargo::canDo() const;
 * @note UnloadCargo vaatii myös että suorittajan ruumassa on lastia, suorittajalla on sijainti
 *       ja että sijainti voi huolia lastia, eli siellä asuu joku ja siellä on taloutta.
 * @copydoc IAction::canDo()
 */

/**
 * @fn virtual bool Common::UnloadCargo::execute();
 * @copydoc IAction::execute()
 * @post Suorittajalla ei ole enää lastia.
 */

/**
  * @private
*/
    //! Toiminnon suorittava alus.
    //! @variable std::shared_ptr<CargoShip> executor_;

#endif
// EOF: unloadcargo.fin.hh
