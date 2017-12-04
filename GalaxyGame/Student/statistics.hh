#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "istatistics.hh"
#include "stateexception.hh"

namespace Student {
class Statistics : public Common::IStatistics
{

// All the game's statistics

public:
    static const int MAX_LOAN_ALLOWANCE; // MAX DEBT FOR PLAYER

    Statistics(const int& startBalance);
    ~Statistics();

    void addSavedShip();
    unsigned getSavedShips() const;

    void addLostShip();
    unsigned getLostShips() const;

    void addPoints(unsigned amount);
    void reducePoints(unsigned amount);
    unsigned getPoints() const;

    void addCredits(unsigned amount);
    void reduceCredits(unsigned amount);
    int getCreditBalance() const;

    void reset();

private:
    unsigned savedShips_;
    unsigned lostShips_;
    unsigned points_;
    int creditBalance_;

};
}//Student

#endif // STATISTICS_HH
