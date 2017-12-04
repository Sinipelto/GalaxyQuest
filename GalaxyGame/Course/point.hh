#ifndef POINT_HH
#define POINT_HH

#include <string>

#include "utility.hh"
#ifdef English_dox
/**
 * @file
 * @brief Point in XY coordinate system.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Used to describe a location of a star system in XY coordinate system.
 *
 * Although point is a struct, it has simple functions, e.g. to compare equality of two points
 * and distance between two points.
 */
#endif
struct Point
{
#ifdef English_dox
    /**
     * @brief Constructor.
     * @param ux X coordinate.
     * @param uy Y coordinate.
     */
#endif
    Point(int ux, int uy) : x(ux), y(uy)
    {
    }
#ifdef English_dox
    //! X coordinate
#endif
    int x;
#ifdef English_dox
    //! Y coordinate
#endif
    int y;
#ifdef English_dox
    /**
     * @brief Overloaded operation to compare the point to another one.
     * @param other Point, which this point is compared to.
     * @return True, if both the coordinates of the points are the same. Otherwise false.
     */
#endif
    bool operator == (const Point& other) const
    {
        return (x == other.x && y == other.y);
    }
#ifdef English_dox
    /**
     * @brief Compares the point to another one.
     * @param other Point, which this point is compared to.
     * @return Distance between two points.
     */
#endif
    double distanceTo(Point other)
    {
        return distance(x, y, other.x, other.y);
    }
#ifdef English_dox
    /**
     * @brief Makes a string from a point.
     * @return String is of the form "x, y".
     */
#endif
    std::string toString()
    {
        return std::to_string(x) + ", " + std::to_string(y);
    }
};

} //Common
#endif // POINT_HH
