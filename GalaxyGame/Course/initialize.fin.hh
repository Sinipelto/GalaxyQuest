#ifdef Finnish_dox

/**
* @file initialize.hh
* @brief Moduuli, joka sisältää ohjelman alustukseen liittyvät funktiot.
* * Tätä moduulia käytetään yhdistämään kurssin puolen koodi
* * opiskelijoiden toteuttaman kanssa.
*/

/**
  @namespace Common
*/

/**
* @typedef typedef std::function<std::shared_ptr<Common::Ship>(std::shared_ptr<Common::StarSystem>,
                                            std::shared_ptr<Common::IEventHandler>)> BuildFunction;
*/

/**
* @fn std::shared_ptr<IGameRunner> Common::getGameRunner(std::shared_ptr<IGalaxy> galaxy,
                                   std::shared_ptr<IEventHandler> handler);
* @brief getGameRunner luo IGameRunner-rajapinnan toteuttavan luokan olion.
*
* @post Luotu IGameRunner on assosioitu galaksin ja eventpasserin kanssa.
* @post Parametrina annettu galaksi on populoitu tähtijärjestelmillä.
* @param galaxy Galaksi, jonka kanssa palautettava olio assosioidaan.
* @param handler Tapahtumankäsittelijä, jonka kanssa palautettava olio assosioidaan.
* @exception IOException Tiedostoa Assets/starsystems.json ei voinut avata luettavaksi.
* @exception FormatException Tiedoston Assets/starsystems.json formaatti ei ole validi.
* @return Luotu olio.
*/


/**
* @fn void Common::addNewShipType(std::string typeName, BuildFunction buildFunction);
* @brief addNewShipType rekisteröi uuden alustyypin rakentamista varten
* @post  Uutta alustyyppiä edustavia aluksia voi luoda
* @param typeName Uuden alustyypin tyyppinimi
* @param buildFunction Uuden alustyypin rakennusfunktio
* @note  Tätä funktiota tarvitsee käyttää ainoastaan, mikäli halutaan toteuttaa uusia aluksia tai moottoreita lisäosana.
*/


#endif

//EOF: initialize.fin.hh
