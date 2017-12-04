#ifdef Finnish_dox

/**
 * @file shipnamegenerator.hh
 * @brief Generoi koleita nimiä aluksille.
 */
 
/**
  @namespace Course
*/

/**
 * @class Course::ShipNameGenerator
 * @brief Generoi koleita nimiä aluksille.
 *
 * Hyödyntää esigeneroitua syötetiedostoa, jonka tulee sisältää tarpeeksi nimiä.
 * Jos sitä ei löydy, nimiä ei generoida aluksille.
 */

/**
 * @fn Course::ShipNameGenerator::ShipNameGenerator();
 * @brief Rakentaja. Yrittää myös lukea syötetiedoston.
 * @post Poikkeustakuu: basic
 * @exception IOException Tiedostoa Assets/shipnames.txt ei voinut avata luettavaksi.
 */

/**
 * @fn Course::ShipNameGenerator::getRandomName();
 * @brief Valitsee satunnaisen nimen esigeneroitujen nimien joukosta. Ei palauta samaa
 * nimeä kahdesti, ellei syötetiedostossa ole samaa nimeä useaan kertaan.
 * @note Jos alusten nimiä ei ole jäljellä, palauttaa tyhjän merkkijonon.
 * @post Poikkeustakuu: nothrow
 * @return Valittu nimi.
 */

/**
  * @private
*/

/**
 * @var bool ShipNameGenerator::shipNames_;
 * @brief Kaikki käyttämättömät aluksen nimet.
 */

// EOF: shipnamegenerator.fin.hh
#endif
