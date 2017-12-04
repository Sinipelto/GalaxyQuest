#include "galaxy.hh"

using namespace Common;

Student::Galaxy::Galaxy():
    systemVector_(),
    shipVector_()
{
}

Student::Galaxy::~Galaxy()
{
    // Delete every starsystem pointer in galaxy
    for (StarSystem::StarSystemVector::iterator i=systemVector_.begin();i!=systemVector_.end();i++) {
        *i = nullptr;
    }
    // Delete every ship pointer in galaxy
    for (ShipVector::iterator i=shipVector_.begin();i!=shipVector_.end();i++) {
        *i = nullptr;
    }
}


void Student::Galaxy::addShip(std::shared_ptr<Common::Ship> ship)
{
    // Check if ship exists
    for (ShipVector::const_iterator iter = shipVector_.begin();iter!=shipVector_.end();iter++) {
        if (*iter == ship) {
            // Ship already exists
            throw StateException("Ship already in this galaxy");
        }
    }
    shipVector_.push_back(ship);
}

void Student::Galaxy::removeShip(std::shared_ptr<Common::Ship> ship)
{
    for (ShipVector::const_iterator iter = shipVector_.begin();iter != shipVector_.end();iter++) {
        if (*iter == ship) {
            shipVector_.erase(iter);
            return; // Skip the rest of the loop and return
        }
    }
    throw ObjectNotFoundException("Ship does not exist in this galaxy");
}

void Student::Galaxy::addStarSystem(std::shared_ptr<Common::StarSystem> starSystem)
{
    for (StarSystem::StarSystemVector::const_iterator iter = systemVector_.begin();iter != systemVector_.end();iter++) {
        if (iter->get() == starSystem.get()) {
            // If same galaxy is being added twice
            throw StateException("This StarSystem is already in galaxy");
        }
        else if (iter->get()->getName() == starSystem->getName()) {
            // Already a system with same name
            throw StateException("StarSystem with same name already exists");
        }
        else if (iter->get()->getId() == starSystem->getId()) {
            // Id already used
            throw StateException("StarSystem with same id already exists");
        }
        else if (iter->get()->getCoordinates() == starSystem->getCoordinates()) {
            // coords already in use
            throw StateException("StarSystem with same coordinates already exists");
        }
    }
    systemVector_.push_back(starSystem);
}

std::shared_ptr<Common::IGalaxy::ShipVector> Student::Galaxy::getShips()
{
    std::shared_ptr<ShipVector> ptr = std::make_shared<ShipVector>(shipVector_); // all ships in galaxy
    return ptr;
}

std::shared_ptr<StarSystem::StarSystemVector> Student::Galaxy::getSystems()
{
    std::shared_ptr<StarSystem::StarSystemVector> ptr = std::make_shared<StarSystem::StarSystemVector>(systemVector_);
    return ptr;
}

Common::StarSystem::StarSystemVector Student::Galaxy::getSystemsInRange(std::shared_ptr<Common::StarSystem> origin, int range)
{
    if (isEmpty()) throw ObjectNotFoundException("Galaxy is empty");

    StarSystem::StarSystemVector::const_iterator iter = systemVector_.begin();
    for (;iter!=systemVector_.end();iter++) {
        if (*iter == origin) {
            break;
        }
    }
    if (iter == systemVector_.end()) {
        throw ObjectNotFoundException("Star system not found in this galaxy");
    }

    StarSystem::StarSystemVector systemsInRange = {};

    for (StarSystem::StarSystemVector::const_iterator iter2 = systemVector_.begin(); iter2 != systemVector_.end() ; iter2++) {
        if (iter2->get()->getCoordinates().distanceTo(origin->getCoordinates()) <= range) {
            if (iter2 == iter) continue; // Skipping the origin itself
            systemsInRange.push_back(*iter2);
        }
    }
    return systemsInRange;
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getRandomSystem()
{
    if (isEmpty()) throw ObjectNotFoundException("This galaxy is empty"); // If galaxy is empty

    int offset = randomMinMax(0, int(systemVector_.size() - 1)); // create an offset int with boundaries of vector size
    std::vector<std::shared_ptr<StarSystem>>::const_iterator iter = systemVector_.begin(); // create iterator for systemvector
    iter += offset; // add offset to vector iterator
    return *iter; // return the pointer of which starsystem the iter is currently pointing
}

Common::IGalaxy::ShipVector Student::Galaxy::getShipsInStarSystem(std::string name)
{
    if (isEmpty()) throw ObjectNotFoundException("Galaxy is empty");

    ShipVector shipsInSystem = {};

    StarSystem::StarSystemVector::const_iterator system = systemVector_.begin();

    for (; system != systemVector_.end();system++) {
        if (system->get()->getName() == name) {
            break; // Iter now set to found system
        }
    }
    if (system == systemVector_.end()) throw ObjectNotFoundException("System with name: " + name + " not found");

    for (ShipVector::const_iterator iter = shipVector_.begin(); iter != shipVector_.end(); iter++) {
        if (iter->get()->getLocation() == *system) {
            shipsInSystem.push_back(*iter);
        }
    }

    return shipsInSystem;
}

std::vector<std::string> Student::Galaxy::getSystemNames()
{
    std::vector<std::string> stringVector = {};

    if (isEmpty()) return stringVector; // Returning empty vector if galaxy is empty

    for (StarSystem::StarSystemVector::const_iterator iter = systemVector_.begin(); iter != systemVector_.end(); iter++) {
        stringVector.push_back(iter->get()->getName());
    }
    return stringVector;
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getStarSystemByName(std::string name)
{
    if (isEmpty()) throw ObjectNotFoundException("This galaxy is empty");

    for (StarSystem::StarSystemVector::const_iterator iter = systemVector_.begin();iter != systemVector_.end();iter++) {
        if (iter->get()->getName() == name) { // presume: no duplicate names
            return *iter;
        }
    }
    throw ObjectNotFoundException("StarSystem with given name was not found in the galaxy");
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getStarSystemById(unsigned id)
{
    if (isEmpty()) throw ObjectNotFoundException("This galaxy is empty");

    for (StarSystem::StarSystemVector::const_iterator iter = systemVector_.begin(); iter != systemVector_.end(); iter++) {
        if (iter->get()->getId() == id) { // pre: no duplicate ids
            return *iter;
        }
    }
    throw ObjectNotFoundException("System with given id was not found in the galaxy");
}

void Student::Galaxy::removeAllShips()
{
    for (auto iter = shipVector_.begin();iter!=shipVector_.end();iter++) {
        *iter = nullptr;
    }
    shipVector_.clear();
}

bool Student::Galaxy::isEmpty() const {
    if (systemVector_.empty()) return true;
    return false;
}
