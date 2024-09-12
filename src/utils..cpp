// utils.cpp
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "utils.hpp"

// Function to show the current date
void showDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);

    std::cout << std::endl << "Current Date: " 
              << std::put_time(localTime, "%Y-%m-%d") << std::endl;
}

// Function to show the current time
void showTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);

    std::cout << std::endl << "Current Time: " 
              << std::put_time(localTime, "%H:%M:%S") << std::endl;
}

// Function to show the time zone
void showTimeZone() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);

    char timeZone[6];
    std::strftime(timeZone, sizeof(timeZone), "%z", localTime);
    std::cout << std::endl << "Time Zone: UTC" << timeZone << std::endl;
}
