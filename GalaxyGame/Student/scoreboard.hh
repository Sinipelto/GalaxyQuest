#ifndef SCOREBOARD_HH
#define SCOREBOARD_HH

#include "complex.hh"
#include "ioexception.hh"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <vector>

namespace Student {
class ScoreBoard {

// The highscores

public:
    typedef std::pair<QString, unsigned> Entry;

    ScoreBoard();
    void loadScores();
    void saveScores();
    void addEntry(Entry entry);

    std::vector<Entry> getBoard() const;

private:
    QString filename_;
    std::vector<Entry> board_;
};
}

#endif // SCOREBOARD_HH
