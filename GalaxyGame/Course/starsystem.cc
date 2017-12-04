#include "starsystem.hh"

namespace Common {

const int StarSystem::POPULATION_REPAIR_TRESHOLD = 1000000;


StarSystem::StarSystem(std::string name,
                       ECONOMY_TYPE economy,
                       unsigned id,
                       uint64_t population,
                       Point location) :
    name_(name),
    economy_(economy),
    id_(id),
    population_(population),
    coordinates_(location)
{

}

std::string StarSystem::getName() const
{
    return name_;
}

StarSystem::ECONOMY_TYPE StarSystem::getEconomy() const
{
    return economy_;
}

unsigned StarSystem::getId() const
{
    return id_;
}

uint64_t StarSystem::getPopulation() const
{
    return population_;
}

Point StarSystem::getCoordinates() const
{
    return coordinates_;
}

bool StarSystem::isInhabited() const
{
    return population_ != 0;
}

bool StarSystem::canRepair() const
{
    if (population_ > POPULATION_REPAIR_TRESHOLD ||
        economy_ == ECONOMY_TYPE::Industrial ||
        economy_ == ECONOMY_TYPE::Military ||
        economy_ == ECONOMY_TYPE::Service ||
        economy_ == ECONOMY_TYPE::HiTech)
    {
        return true;
    }

    return false;
}

} //Common
