#include "../include/Logger.h"
#include <chrono>
#include <ctime>

enum class LogType {
    INFO,
    WARNING,
    ERROR
};

Logger::Logger(const std::string& filename) : m_filename(filename) {}

template<typename T>
void Logger::log(const T& message, LogType logType) {
    std::ofstream file(m_filename, std::ios_base::app); // Abre el archivo en modo de agregar
    if (file.is_open()) {
        // Obtén la hora actual
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        char buf[100] = {0};
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now_c));

        // Convierte el tipo de registro a string
        std::string logTypeStr;
        switch (logType) {
            case LogType::INFO:
                logTypeStr = "INFO";
                break;
            case LogType::WARNING:
                logTypeStr = "WARNING";
                break;
            case LogType::ERROR:
                logTypeStr = "ERROR";
                break;
        }

        // Escribe la hora, el tipo de registro y el mensaje en el archivo de log
        file << "[" << buf << "] [" << logTypeStr << "] " << message << std::endl;
    }
}
