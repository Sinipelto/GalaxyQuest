#ifndef SHIPNAMEGENERATOR_HH
#define SHIPNAMEGENERATOR_HH

#include <vector>
#include <string>

#ifdef English_dox
/**
 * @file shipnamegenerator.hh
 * @brief Generates cool names for ships.
 */
#endif
namespace Course {

#ifdef English_dox
/**
 * @brief Generates cool names for ships.
 *
 * Relies on a pregenerated input file to contain enough names.
 * If it does not exist, one does not simply generate names for ships.
 */
#endif
class ShipNameGenerator
{
public:
#ifdef English_dox
    /**
     * @brief Constructor. Will also read the input file.
     * @post Exception guarantee: basic
     * @exception IOException Could not open file Assets/shipnames.txt for reading.
     */
#endif
    ShipNameGenerator();
#ifdef English_dox
    /**
     * @brief Picks a random name from the pregenerated names. Will not yield the same
     * name twice, unless the input file contained it more than once.
     * @note If there are no more ship names, will return an empty string.
     * @post Exception guarantee: nothrow
     * @return The picked name.
     */
#endif
    std::string getRandomName();
private:
#ifdef English_dox
    //! All unused ship names.
#endif
    std::vector<std::string> shipNames_;
};

}//Course
#endif // SHIPNAMEGENERATOR_HH
