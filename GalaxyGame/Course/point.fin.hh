#ifdef Finnish_dox

/**
 * @file point.hh
 * @brief Piste XY-koordinaatistossa.
 */

/**
  @namespace Common
*/

/**
 * @struct Common::Point
 * @brief Pisteen avulla ilmoitetaan tähtijärjestelmän sijainti XY-koordinaatistossa.
 *
 * Vaikka piste onkin tietue, sisältää se yksinkertaisia apufunktioita, kuten kahden pisteen
 * yhtäsuuruusvertailu sekä sijainti kahden pisteen välillä.
 */

/**
 * @fn Common::Point::Point(int ux, int uy) : x(ux), y(uy) { }
 * @brief Rakentaja.
 * @param ux X-koordinaatti.
 * @param uy Y-koordinaatti.
 */

//! X-koordinaatti
//! @variable int x;
//! Y-koordinaatti
//! @variable int y;

/**
 * @fn bool Common::Point::operator == (const Point& other) const { return (x == other.x && y == other.y); }
 * @brief Ylikuormitettu operaatio, joka vertaa pistettä toiseen pisteeseen.
 * @param other Piste, johon verrataan tätä pistettä.
 * @return Tosi, jos pisteiden kesken molemmat koordinaatit ovat samat. Muutoin epätosi.
 */

/**
 * @fn double Common::Point::distanceTo(Point other){ return distance(x, y, other.x, other.y); }
 * @brief Vertaa pistettä toiseen pisteeseen.
 * @param other Piste, johon verrataan tätä pistettä.
 * @return Etäisyys kahden pisteen välillä.
 */

/**
 * @fn std::string Common::Point::toString() { return std::to_string(x) + ", " + std::to_string(y); }
 * @brief Tekee pisteestä merkkijonon.
 * @return Merkkijono muotoa "x, y".
 */

#endif
// EOF: point.fin.hh
