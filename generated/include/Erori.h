#ifndef ERORI_H
#define ERORI_H

#include <stdexcept>
#include <string>

class ScoreFileException : public std::runtime_error {
public:
    explicit ScoreFileException(const std::string& message);
};

class ScoreFileOpenError : public ScoreFileException {
public:
    ScoreFileOpenError();
};

class ScoreFileReadError : public ScoreFileException {
public:
    ScoreFileReadError();
};

class ScoreFileFormatError : public ScoreFileException {
public:
    ScoreFileFormatError();
};

#endif // ERORI_H