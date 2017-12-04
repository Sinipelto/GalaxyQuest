#include "shipnamegenerator.hh"
#include "ioexception.hh"
#include <QFile>
#include <algorithm>
namespace Course {

QString const SHIPNAME_FILE = "Assets/shipnames.txt";

ShipNameGenerator::ShipNameGenerator():
    shipNames_()
{

    QFile nameFile (SHIPNAME_FILE);
    if(!nameFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
      throw Common::IoException("Could not read file");
    }
    while (!nameFile.atEnd()){
        QString name = nameFile.readLine().trimmed();
        shipNames_.push_back(name.toStdString());
    }
    std::random_shuffle(shipNames_.begin(), shipNames_.end());

}

std::string ShipNameGenerator::getRandomName()
{
    std::string name = "";
    if(!shipNames_.empty()){
        name = shipNames_.back();
        shipNames_.pop_back();
    }
    return name;
}
}//Course
