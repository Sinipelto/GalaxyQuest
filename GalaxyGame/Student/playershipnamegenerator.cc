#include "playershipnamegenerator.hh"

const QString FILENAME = "Assets/playershipnames.txt";

Student::PlayerShipNameGenerator::PlayerShipNameGenerator():
    shipNames_()
{
    QFile file(FILENAME);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw Common::IoException("Name file could not be read");
    }
    while (!file.atEnd()) {
        QString name = file.readLine().trimmed();
        shipNames_.push_back(name);
    }
    file.close();
    std::random_shuffle(shipNames_.begin(), shipNames_.end());
}

QString Student::PlayerShipNameGenerator::getRandomName() const
{
    int randomIndex = Common::randomMinMax(0, int (shipNames_.size()) - 1);
    std::vector<QString>::const_iterator randomIter = shipNames_.begin();
    randomIter += randomIndex;
    return *randomIter;
}
