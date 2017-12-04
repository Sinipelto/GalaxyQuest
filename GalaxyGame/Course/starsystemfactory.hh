#ifndef STARSYSTEMFACTORY_HH
#define STARSYSTEMFACTORY_HH

#include "starsystem.hh"
#include "point.hh"
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <string>
#include <memory>
#include <vector>

#ifdef English_dox
/**
 * @file starsystemfactory.hh
 * @brief Singleton class that creates star systems.
 */
#endif
namespace Course {

#ifdef English_dox
/**
 * @brief Singleton class for creating star systems.
 *
 * The factory is requested to read JSON file, after which it will requested to
 * return a data structure, which containts the read star systems.
 */
#endif
class StarSystemFactory
{
public:
    #ifdef English_dox
    /**
     * @post Exception guarantee: nothrow
     * @return A reference to the factory.
     */
    #endif
    static StarSystemFactory& getInstance();
    #ifdef English_dox
    /**
     * @brief Reads star systems a JSON file.
     * @post The JSON file containing the star systems is read.
     * @post Exception guarantee: basic
     * @param filename Name of a file, which is located at GalaxyGame/Assets.
     * @exception IOException Could not open the file for reading.
     * @exception FormatException Format of the JSON file is invalid.
     */
    #endif
    void readJSON(std::string filename);
    #ifdef English_dox
    /**
     * @post Exception guarantee: nothrow
     * @return The star systems read from the JSON file. If the file is not read,
     * or the star systems did not exist, will return an empty vector.
     */
    #endif
    Common::StarSystem::StarSystemVector getAllStarSystems();
    #ifdef English_dox
    /**
     * @post Exception guarantee: nothrow
     * @return True, if a JSON file is successfully read, else false.
     */
    #endif
    bool isJSONread() const;

private:
    StarSystemFactory();
    std::shared_ptr<Common::StarSystem> jsonToStarSystem(QJsonObject object);
    std::string parseName(QJsonValue name);
    Common::StarSystem::ECONOMY_TYPE parseEconomy(QJsonValue information);
    int parseId(QJsonValue id);
    unsigned long parsePopulation(QJsonValue information);

    Common::Point parseCoordinates(QJsonValue coordinates);

    bool filterByZCoordinate(QJsonObject object);

    QJsonArray systemArray_;

};

}//Course
#endif // STARSYSTEMFACTORY_HH
