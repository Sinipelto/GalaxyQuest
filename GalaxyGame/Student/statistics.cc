#include "statistics.hh"

using namespace Common;

const int Student::Statistics::MAX_LOAN_ALLOWANCE = -2000;

Student::Statistics::Statistics(const int& startBalance):
    savedShips_(0),
    lostShips_(0),
    points_(0),
    creditBalance_(startBalance) // The initial balance for player
{
}

Student::Statistics::~Statistics()
{
}

void Student::Statistics::addSavedShip()
{
    savedShips_++;
}

unsigned Student::Statistics::getSavedShips() const
{
    return savedShips_;
}

void Student::Statistics::addLostShip()
{
    lostShips_++;
}

unsigned Student::Statistics::getLostShips() const
{
    return lostShips_;
}

void Student::Statistics::addPoints(unsigned amount)
{
    points_+=amount;
}

void Student::Statistics::reducePoints(unsigned amount)
{
    if (int (points_-amount) < 0) {
        points_ = 0;
        throw StateException("Points cant be negative.");
    }
    points_-=amount;
}

unsigned Student::Statistics::getPoints() const
{
    return points_;
}

void Student::Statistics::addCredits(unsigned amount)
{
    creditBalance_+=amount;
}

void Student::Statistics::reduceCredits(unsigned amount)
{
    if ((creditBalance_ - int(amount)) < MAX_LOAN_ALLOWANCE) {
        throw Common::StateException("Balance cannot exceed MAX_LOAN_ALLOWANCE");
    }
    creditBalance_-=amount;
}

int Student::Statistics::getCreditBalance() const
{
    return creditBalance_;
}

void Student::Statistics::reset()
{
    savedShips_ = 0;
    lostShips_ = 0;
    points_ = 0;
    creditBalance_ = 0;
}
