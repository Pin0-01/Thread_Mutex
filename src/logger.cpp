#include "../include/logger.hpp"
#include <iostream>
#include <mutex>

void Logger::log(const std::string& messagge) {
    
    std::lock_guard<std::mutex> lock(mtx);

    std::cout << "[LOG]: " << messagge << std::endl;
}