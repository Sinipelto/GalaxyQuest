#ifndef UTILITY_HH
#define UTILITY_HH

#ifdef English_dox
/**
 * @file
 * @brief Module providing functions for general use.
 */
#endif
namespace Common
{
#ifdef English_dox
    /**
     * @brief Initializes utility module.
     * @pre Module has not been initialized.
     * @post Module has been initialized.
     * @param seed Seed value of random number generator (See internet).
     */
#endif
    void utilityInit(int seed);
#ifdef English_dox
    /**
     * @brief Lots a number.
     * @pre Module has been initialized.
     * @pre min <= max.
     * @param min Smallest possible number.
     * @param max Greatest possible number.
     * @return Lotted number.
     */
#endif
    int randomMinMax(int min, int max);
#ifdef English_dox
    /**
     * @brief Calculates distance between two points.
     * @pre Module has been initialized.
     * @param x1 x coordinate of the first point.
     * @param y1 y coordinate of the first point.
     * @param x2 x coordinate of the second point.
     * @param y2 y coordinate of the second point.
     * @return Calculated distance.
     */
#endif
    double distance(double x1, double y1, double x2, double y2);
}

#endif // UTILITY_HH
