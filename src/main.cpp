#include "../include/logger.hpp"
#include <thread>
#include <vector>
#include <string>

void trySensor(int id, Logger& logger) {
    for (int i = 0; i < 3; ++i) {
        std::string msg = "Sensor cod." + std::to_string(id) + " data reveiling.. " + std::to_string(i);
        logger.log(msg);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    Logger myLogger;
    std::vector<std::thread> threadList;
    
    for (int i = 1; i <= 5; ++i) {
        threadList.push_back(std::thread(trySensor, i, std::ref(myLogger)));
    }

    for (auto& t : threadList) {
        t.join();
    }

    return 0;
}