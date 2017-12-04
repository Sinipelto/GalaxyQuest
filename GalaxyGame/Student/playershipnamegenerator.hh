#ifndef PLAYERSHIPNAMEGENERATOR_HH
#define PLAYERSHIPNAMEGENERATOR_HH

#include "ioexception.hh"
#include "utility.hh"
#include <vector>
#include <QFile>
#include <QString>
#include <algorithm>

namespace Student {
class PlayerShipNameGenerator
{

// Used to generate random name to the player ship in the start dialog

public:
    PlayerShipNameGenerator();
    QString getRandomName() const;

private:
    std::vector<QString> shipNames_;
};
}//Student

#endif // PLAYERSHIPNAMEGENERATOR_HH
