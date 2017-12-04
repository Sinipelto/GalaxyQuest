#ifdef Finnish_dox

/**
 * @file loadcargo.hh
 * @brief Lastaustoiminto.
 */

/**
  @namespace Common
*/

/**
 * @class Common::LoadCargo : public IAction
 * @brief Rahtialukset lastaavat lastinsa tällä toiminnolla.
 *
 * Lasti pitää lastata sellaisessa tähtijärjestelmässä, joka voi luovuttaa lastia.
 */

/**
 * @fn Common::LoadCargo::LoadCargo(std::shared_ptr<CargoShip> executor);
 * @brief Rakentaja.
 * @post Toiminnolle on assosioitu toimintoa suorittava alus.
 * @param executor Toiminnon suorittava alus.
 */

/**
 * @fn virtual bool Common::LoadCargo::canDo() const;
 * @copydoc IAction::canDo()
 * @note LoadCargo vaatii myös, että suorittajan ruuma on tyhjä, että suorittajalla on sijainti
 *       ja että sijainti voi luovuttaa lastia, eli siellä asuu joku ja siellä on taloutta.
 */

/**
 * @fn virtual bool Common::LoadCargo::execute();
 * @copydoc IAction::execute()
 * @post Suorittajalla on lastattuna tähtijärjestelmän taloustyypin mukainen lasti.
 */

/**
  * @private
*/
    //! Toiminnon suorittava alus.
    //! @variable std::shared_ptr<CargoShip> executor_;

#endif
// EOF: loadcargo.fin.hh
