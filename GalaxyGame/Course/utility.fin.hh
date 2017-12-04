#ifdef Finnish_dox

/**
 * @file utility.hh
 * @brief Yleiskäyttöisiä funktioita sisältävä moduuli.
 */

/**
  @namespace Common
*/

/**
 * @fn void Common::utilityInit(int seed);
 * @brief Alustaa utility-moduulin.
 * @pre Moduulia ei ole alustettu.
 * @post Moduuli on alustettu.
 * @param seed Satunnaislukugeneraattorin alustusarvo (Katso verkkolähteistä).
 */

/**
 * @fn int Common::randomMinMax(int min, int max);
 * @brief Arpoo luvun.
 * @pre Moduuli on alustettu.
 * @pre min <= max.
 * @param min Pienin mahdollinen luku.
 * @param max Suurin mahdollinen luku.
 * @return Arvottu luku.
 */

/**
 * @fn double Common::distance(double x1, double y1, double x2, double y2);
 * @brief Laskee etäisyyden kahden pisteen välillä.
 * @pre Moduuli on alustettu.
 * @param x1 Ensimmäisen pisteen x-coordinaatti.
 * @param y1 Ensimmäisen pisteen y-coordinaatti.
 * @param x2 Toisen pisteen x-coordinaatti.
 * @param y2 Toisen pisteen y-coordinaatti.
 * @return Laskettu etäisyys.
 */

#endif
// EOF: utility.fin.hh
