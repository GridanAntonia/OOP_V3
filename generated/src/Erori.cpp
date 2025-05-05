#include "Erori.h"

ScoreFileException::ScoreFileException(const std::string& message)
    : std::runtime_error(message) {}

ScoreFileOpenError::ScoreFileOpenError()
    : ScoreFileException("Error opening file") {}

ScoreFileReadError::ScoreFileReadError()
    : ScoreFileException("Error reading file") {}

ScoreFileFormatError::ScoreFileFormatError()
    : ScoreFileException("Error in file format") {}