#include "scoreboard.hh"

const QString FILENAME = "Assets/scores.txt";

Student::ScoreBoard::ScoreBoard():
    board_()
{
    loadScores();
}

void Student::ScoreBoard::loadScores()
{
    QFile file(FILENAME);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw Common::IoException("Score file could not be opened");
    }

    while (!file.atEnd()) {
        auto data = file.readLine().trimmed().split(';');
        auto name = data.first();
        auto score = data.last().toUInt();
        if (name == "") {
            continue;
        }
        board_.push_back({name, score});
    }
    file.close();
}

void Student::ScoreBoard::saveScores()
{
    QFile file(FILENAME);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw Common::IoException("File could not be opened");
    }

    QTextStream out(&file);
    for (auto iter = board_.begin();iter!=board_.end();iter++) {
        out << iter->first << ";" << iter->second << endl;
    }
    file.close();
}

void Student::ScoreBoard::addEntry(Entry entry)
{
    // Look for old record with same name
    for (auto iter = board_.begin();iter!=board_.end();iter++) {
        if (iter->first == entry.first) {
            board_.erase(iter);
        }
    }

    for (auto iter = board_.begin();iter!=board_.end();iter++) {
        if (iter->second < entry.second) {
            board_.insert(iter, entry);
            if (board_.size() > 10) {
                board_.pop_back();
            }
            return;
        }
    }
    if (board_.size() < 10) {
        board_.push_back(entry);
    }
}

std::vector<Student::ScoreBoard::Entry> Student::ScoreBoard::getBoard() const
{
    return board_;
}
