#ifdef Finnish_dox

/**
 * @file moveaction.hh
 * @brief Liikkumistoiminto.
 */
/**
  @namespace Common
*/

/**
 * @class Common::MoveAction : public IAction
 * @brief Alukset käyttävät liikkumistoimintoa siirtyessään tähtijärjestelmästä toiseen.
 *
 * Liikkumistoiminto on erittäin riippuvainen suorittavan aluksen moottorista, joka
 * käytännössä määrää, onko aluksen mahdollista siirtyä annettuun määränpäähän
 * ja miten nopeasti siitä matkasta suoriudutaan.
 */

/**
 * @fn Common::MoveAction::MoveAction(std::shared_ptr<Ship> executor, std::shared_ptr<StarSystem> destination,
              std::shared_ptr<IEventHandler> events);

 * @brief Rakentaja.
 * @post Toiminnolle on assosioitu toimintoa suorittava alus.
 * @param executor Toiminnon suorittava alus.
 * @param destination Matkan kohde.
 * @param events Tätä kauta spawnataan aluksen eventit. Voi olla myös nullptr.
 */

/**
 * @fn virtual bool Common::MoveAction::canDo() const;
 * @copydoc IAction::canDo()
 * @note MoveAction vaatii myös, että suorittajalla on sijainti sekä ehjä moottori
 *       ja että ilmoitettu määränpää on olemassa sekä moottorin saavutettavissa.
 */

/**
 * @fn virtual bool Common::MoveAction::execute();
 * @copydoc IAction::execute()
 * @post Matkalla on edetty, jos toimintoa ei ole suoritettu loppuun.
 * @post Jos toiminto suoritettiin loppuun, suorittajalla on jokin sijainti.
 */

/**
  * @private
*/
    /**
     * @fn void Common::MoveAction::startTrip();
     * Suorittaa matkan alussa tehtävät asiat.
     * @pre Matkaa ei ole vielä aloitettu.
     */


    /**
     * @fn bool Common::MoveAction::concludeTrip();
     * Katsoo, päättyykö matka, ja jos päättyy, tekee tarvittavat asiat.
     * @returns Tosi, jos matka päättyi. Muutoin epätosi.
     */


    //! Toiminnon suorittava alus.
    //! @variable std::shared_ptr<Ship> executor_;
    //! Matkan kohde.
    //! @variable std::shared_ptr<StarSystem> destination_;
    //! Tätä kautta spawnataan eventit.
    //! @variable std::shared_ptr<IEventHandler> events_;
    //! Tosi, jos matkustus on jo aloitettu.
    //! @variable bool travelling_;

    //! Montako vuoroa ollaan edetty matkalla.
    //! @variable int turns_;
    //! @variable int requiredTurns_;

    // Aluksen sijainti koordinateissa matkan aikana.
    //! @variable double x_pos_;
    //! @variable double y_pos_;

    // Aluksen siirtymä kullakin vuorolla.
    //! @variable double x_diff_;
    //! @variable double y_diff_;

#endif
// EOF: moveaction.fin.hh
