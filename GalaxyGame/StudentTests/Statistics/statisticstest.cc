#include "istatistics.hh"
#include "statistics.hh"
#include "stateexception.hh"
#include <QtTest>
#include <QtDebug>
#include <memory>

using namespace Common;

class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();
    ~StatisticsTest();

private Q_SLOTS:
    void init();
    void testConstructor();
    void testAddSavedShip();
    void testAddLostShip();
    void testAddCredits();
    void testAddPoints();
    void testReducePointsMaximum();
    void testReduceCreditsMaximum();
    void testReducePointsBelowZero();
    void testDebtExceeded();

private:
    std::shared_ptr<Student::Statistics> statistics_;
};

StatisticsTest::StatisticsTest():
    statistics_(nullptr)
{
}

StatisticsTest::~StatisticsTest()
{
    statistics_ = nullptr;
}

void StatisticsTest::init()
{
    statistics_.reset();
    statistics_ = std::make_shared<Student::Statistics>(5000);
}

void StatisticsTest::testConstructor()
{
    QVERIFY2(statistics_->getSavedShips() == 0, "Number of saved ships not the appropriate starting value.");
    QVERIFY2(statistics_->getLostShips() == 0, "Number of lost ships not the appropriate starting value.");
    QVERIFY2(statistics_->getPoints() == 0, "Number of points not the appropriate starting value.");
    QVERIFY2(statistics_->getCreditBalance() == 5000, "Number of credits not the appropriate starting value.");
}

void StatisticsTest::testAddSavedShip()
{
    unsigned currentShips = statistics_->getSavedShips();
    statistics_->addSavedShip();
    QCOMPARE(statistics_->getSavedShips(), currentShips + 1);
}

void StatisticsTest::testAddLostShip()
{
    unsigned currentShips = statistics_->getLostShips();
    statistics_->addLostShip();
    QCOMPARE(statistics_->getLostShips(), currentShips + 1);
}

void StatisticsTest::testAddCredits()
{
    int creditsNow = statistics_->getCreditBalance();
    statistics_->addCredits(123);
    QCOMPARE(statistics_->getCreditBalance(), creditsNow + 123);
}

void StatisticsTest::testAddPoints()
{
    unsigned pointsNow = statistics_->getPoints();
    statistics_->addPoints(123);
    QCOMPARE(statistics_->getPoints(), pointsNow + 123);
}

void StatisticsTest::testReducePointsBelowZero()
{
    QVERIFY_EXCEPTION_THROWN(statistics_->reducePoints(statistics_->getPoints() + 1), StateException); // Test dropping points below zero
    QVERIFY2(statistics_->getPoints() == 0, "Player points should be zero after reduction"); // Points should be zero now
}

void StatisticsTest::testDebtExceeded()
{
    int currentBalance = statistics_->getCreditBalance();
    unsigned testValue = unsigned(statistics_->getCreditBalance() - statistics_->MAX_LOAN_ALLOWANCE + 1);
    qDebug() << "Value to try: " << testValue;

    // Debt shall not exceed the set max loan value
    QVERIFY_EXCEPTION_THROWN(statistics_->reduceCredits(testValue), StateException); // Dropping credits under MAX_LOAN_ALLOWANCE
    QVERIFY2(statistics_->getCreditBalance() == currentBalance, "Player credit balance should remain unchanged if max loan value is exceeded");
}

void StatisticsTest::testReducePointsMaximum()
{
    // Test that points are reduced to exactly zero
    statistics_->reducePoints(statistics_->getPoints());
    QVERIFY(statistics_->getPoints() == 0);
}

void StatisticsTest::testReduceCreditsMaximum()
{
    // Test reducing credits to the maximum allowed debt
    QVERIFY2(statistics_->getCreditBalance() >= 0, "Balance should be positive in this test");
    unsigned value = unsigned(statistics_->getCreditBalance() - Student::Statistics::MAX_LOAN_ALLOWANCE);
    qDebug() << "Value to try: " << value;
    statistics_->reduceCredits(value);
    qDebug() << "Balance now: " << statistics_->getCreditBalance();
    QVERIFY(statistics_->getCreditBalance() == Student::Statistics::MAX_LOAN_ALLOWANCE);
}

QTEST_APPLESS_MAIN(StatisticsTest)

#include "statisticstest.moc"
