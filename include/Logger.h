#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

enum class LogType {
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    Logger(const std::string& filename);
    template<typename T>
    void log(const T& message, LogType logType);

private:
    std::string m_filename;
};

#endif // LOGGER_H