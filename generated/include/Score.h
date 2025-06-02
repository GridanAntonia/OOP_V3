#ifndef SCOR_H
#define SCOR_H

#include <iostream>

template<typename T>
class Score {
private:
    T points;

public:
    Score() : points(0) {}

    explicit Score(T points) : points(points) {}

    void addPoints(T value) {
        points += value;
    }

    T getPoints() const {
        return points;
    }

    friend std::ostream &operator<<(std::ostream &os, const Score<T> &score) {
        os << score.points;
        return os;
    }
};

template<typename T>
Score<T> getMaxScore(const Score<T> &a, const Score<T> &b) {
    return (a.getPoints() > b.getPoints()) ? a : b;
}

#endif // SCOR_H
