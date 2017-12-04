#include "starsystemfactory.hh"


#include "formatexception.hh"
#include "ioexception.hh"

#include <QJsonDocument>
#include <QFile>
#include <cmath>
#include <iostream>
#include <stdint.h>
namespace Course {
using Common::StarSystem;


QString const ASSET_FOLDER("Assets/");

double const Z_LIMIT = 5.0;

StarSystemFactory& StarSystemFactory::getInstance()
{
    static StarSystemFactory instance;
    return instance;
}

void StarSystemFactory::readJSON(std::string filename)
{
    QFile file (ASSET_FOLDER + QString::fromStdString(filename));
    if (!file.open(QFile::ReadOnly))
    {
        throw Common::IoException("Could not read file " + filename);
    }
    QJsonDocument systemJSON = QJsonDocument::fromJson(file.readAll());

    if (systemJSON.isNull()) {
        throw Common::FormatException("JSON parsing failed for input file " + filename);
    }
    else {
        systemArray_=systemJSON.array();
    }

}


Common::StarSystem::StarSystemVector StarSystemFactory::getAllStarSystems()
{
    std::vector<std::shared_ptr<StarSystem>> allSystems;
    for (auto i = 0; i!=systemArray_.size(); i++) {

        if(filterByZCoordinate(systemArray_.at(i).toObject())){
            allSystems.push_back(jsonToStarSystem(systemArray_.at(i).toObject()));
        }
    }
    return allSystems;
}

bool StarSystemFactory::isJSONread() const
{
    return !systemArray_.isEmpty();
}

StarSystemFactory::StarSystemFactory()
{

}

std::shared_ptr<Common::StarSystem> StarSystemFactory::jsonToStarSystem(QJsonObject object)
{
    return std::make_shared<StarSystem>( parseName(object.value("name")),
                                         parseEconomy(object.value("information")),
                                         parseId(object.value("id")),
                                         parsePopulation( object.value("information")),
                                         parseCoordinates(object.value("coords"))
                                         );
}

std::string StarSystemFactory::parseName(QJsonValue name)
{
    return name.toString().toStdString();
}

StarSystem::ECONOMY_TYPE StarSystemFactory::parseEconomy(QJsonValue information)
{
    StarSystem::ECONOMY_TYPE economy = StarSystem::ECONOMY_TYPE::None;
    if(information.toObject().value("economy").toString()=="Refinery") {
        economy = StarSystem::ECONOMY_TYPE::Refinery;
    }
    else if (information.toObject().value("economy").toString()=="Extraction") {
        economy = StarSystem::ECONOMY_TYPE::Extraction;
    }
    else if (information.toObject().value("economy").toString()=="Hi Tech") {
        economy = StarSystem::ECONOMY_TYPE::HiTech;
    }
    else if (information.toObject().value("economy").toString()=="Industrial") {
        economy = StarSystem::ECONOMY_TYPE::Industrial;
    }
    else if (information.toObject().value("economy").toString()=="Tourism") {
        economy = StarSystem::ECONOMY_TYPE::Tourism;
    }
    else if (information.toObject().value("economy").toString()=="Agriculture") {
        economy = StarSystem::ECONOMY_TYPE::Agriculture;
    }
    else if (information.toObject().value("economy").toString()=="Service") {
        economy = StarSystem::ECONOMY_TYPE::Service;
    }
    else if (information.toObject().value("economy").toString()=="Military") {
        economy = StarSystem::ECONOMY_TYPE::Military;
    }
    else if (information.toObject().value("economy").toString()=="Terraforming") {
        economy = StarSystem::ECONOMY_TYPE::Terraforming;
    }
    else if (information.toObject().value("economy").toString()=="Colony") {
        economy = StarSystem::ECONOMY_TYPE::Colony;
    }
    else if (information.toObject().value("economy").toString()=="None") {
        economy = StarSystem::ECONOMY_TYPE::None;
    }
    else {
        economy =StarSystem::ECONOMY_TYPE::None;
    }
    return economy;

}

int StarSystemFactory::parseId(QJsonValue id)
{
    return id.toInt();
}

unsigned long StarSystemFactory::parsePopulation(QJsonValue information)
{
    return static_cast<unsigned long> (information.toObject().value("population").toDouble(0));
}

Common::Point StarSystemFactory::parseCoordinates(QJsonValue coordinates)
{
    return Common::Point( static_cast<int> (round(coordinates.toObject().value("x").toDouble())),
                          static_cast<int> (round(coordinates.toObject().value("y").toDouble())));
}

bool StarSystemFactory::filterByZCoordinate(QJsonObject object)
{
    double distance =  object.value("coords").toObject().value("z").toDouble();
    return -Z_LIMIT <= distance && distance <= Z_LIMIT;

}

}//Course
