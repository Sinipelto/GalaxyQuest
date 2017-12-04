#ifdef Finnish_dox


/**
 * @file igamerunner.hh
 * @brief Rajapintaluokka, jonka kautta ohjataan ja tahditetaan peliä.
 */

/**
  @namespace Common
*/

/**
 * @class Common::IGameRunner
 * @brief Tarjoaa rajapinnan, jonka kautta pelilogiikkaa ohjataan.
 *
 * Pelilogiikka jakautuu kolmeen osaan: Uusien alusten luominen, alusten toimintojen
 * valitseminen sekä alusten toimintojen suorittaminen.
 */

/**
 * @fn Common::IGameRunner::IGameRunner()
 * @brief Rakentaja, olemassa dokumentaatiota varten
 */
 
/**
 * @fn Common::IGameRunner::~IGameRunner()
 * @brief Virtuaalipurkaja. Ei tee mitään, koska kyseessä on rajapintaluokka.
 */
 
/**
 * @fn virtual void Common::IGameRunner::spawnShips(unsigned int count) = 0;
 * @brief Luo uusia satunnaisia aluksia annetun lukumäärän verran ja antaa ne assoioidulle galaksille.
 * @pre Oliolle on jotakin kautta assosioitu galaksi.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn  virtual void Common::IGameRunner::createActions() = 0;
 * @brief Yrittää asettaa assosioidussa galaksissa kaikille sellaisille NPC-aluksille toiminnon,
 *        joilta sellainen puuttuu.
 * @pre Oliolle on jotakin kautta assosioitu galaksi.
 * @post Kaikilla NPC-aluksilla on toiminto, paitsi niillä, joille ei löytynyt sopivaa.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn virtual void Common::IGameRunner::doActions() = 0;
 * @brief Kehoittaa assosioidussa galaksissa kaikkia aluksia suorittamaan toimintonsa.
 * @pre Oliolle on jotakin kautta assosioitu galaksi.
 * @post Poikkeustakuu: nothrow
 */
#endif
// EOF: igamerunner.fin.h

