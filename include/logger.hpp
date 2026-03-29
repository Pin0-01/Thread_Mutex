#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <mutex>

class Logger {
private:
    std::mutex mtx; 

public:
    void log(const std::string& messagge);
};

#endif