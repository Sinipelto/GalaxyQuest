#ifdef Finnish_dox

/**
 * @file distressaction.hh
 * @brief Hätäkutsutoiminto.
 */

/**
  @namespace Common
*/

/**
 * @class Common::DistressAction : public IAction
 * @brief Alukset tekevät hätäkutsuja tällä toiminnolla.
 *
 * Hätäkutsut spawnaavat eventin, joka
 * on tarkoitus jollain tapaa huomioida käyttöliittymässä.
 *
 * Jos hätäkutsu kestää 20 vuoroa, alus hylätään ja siitä spawnataan eventti.
 */
 
//! Hätäkutsun maksimipituus vuoroissa.
//! @variable sstatic unsigned const MAX_DISTRESS_DURATION;

    /**
     * @fn Common::DistressAction::DistressAction(std::shared_ptr<Ship> executor, std::shared_ptr<IEventHandler> events);
     * @brief Rakentaja.
     * @post Toiminnolle on assosioitu toimintoa suorittava alus.
     * @param executor Toiminnon suorittava alus.
     * @param events Tätä kautta spawnataan eventit. Voi olla myös nullptr.
     */


    /**
     * @fn virtual bool Common::DistressAction::canDo() const;
     * @copydoc IAction::canDo()
     * @note DistressAction vaatii myös, että suorittajalla on moottori ja että se on rikki.
     */

    /**
     * @fn virtual bool Common::DistressAction::execute();
     * @copydoc IAction::execute()
     * @post Hätäkutsueventti on spawnattu, mutta vain jos toiminto suoritettiin
     *       ensimmäistä kertaa tämän olion elinkaaren aikana.
     * @post Jos toiminto suoritettiin loppuun, hätäkutsun sammumiseventti on spawnattu.
     * @post Jos hätäkutsu kestää 20 vuoroa, alus hylätään ja toiminto suoritetaan loppuun.
     * @note Toimintoa ei suoriteta loppuun, ennen kuin moottori on korjattu kokonaan.
     */

/**
  * @private
*/
    //! Toiminnon suorittava alus.
    //! @variable std::shared_ptr<Ship> executor_;
    //! Tätä kautta spawnataan eventit.
    //! @variable std::shared_ptr<IEventHandler> events_;
    //! Tosi, jos suorituksen aikana on jo kertalleen spawnattu hätäkutsu.
    //! @variable bool distressAsserted_;
    //! @variable unsigned distressDuration_;

// EOF: distressaction.fin.hh
#endif
