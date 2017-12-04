#include "eventhandler.hh"

using namespace Common;

Student::EventHandler::EventHandler(GameWindow *game):
    game_(game)
{
}

Student::EventHandler::~EventHandler()
{
}

void Student::EventHandler::shipSpawned(std::shared_ptr<Common::Ship> ship)
{
    ship = nullptr;
}

void Student::EventHandler::shipRemoved(std::shared_ptr<Common::Ship> ship)
{
    ship = nullptr;
}

void Student::EventHandler::shipRelocated(std::shared_ptr<Common::Ship> ship, std::shared_ptr<Common::StarSystem> starSystem)
{
    ship = nullptr;
    starSystem = nullptr;
}

void Student::EventHandler::shipMoved(std::shared_ptr<Common::Ship> ship, Common::Point origin, Common::Point target)
{
    ship = nullptr;
    origin.distanceTo(target);
}

void Student::EventHandler::exceptionInExecution(std::shared_ptr<Common::Ship> ship, const std::string &msg)
{
    ship = nullptr;
    if (msg.empty()) return;
}

void Student::EventHandler::distressOn(std::shared_ptr<Common::Ship> ship)
{
    game_->setDistressOn(ship);
}

void Student::EventHandler::distressOff(std::shared_ptr<Common::Ship> ship)
{
    game_->setDistressOff(ship);
}

void Student::EventHandler::shipAbandoned(std::shared_ptr<Common::Ship> ship)
{
    ship = nullptr;
    game_->getStatistics()->addLostShip();
    game_->getStatistics()->reducePoints(50);
}
