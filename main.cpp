#include <chrono>
#include <iostream>
#include <thread>

#include "ChessClock.h"

int main()
{
    chess::ChessClock chessClock{};
    chessClock.start();
    std::this_thread::sleep_for(std::chrono::milliseconds{33});
    chessClock.stopWhite();
    std::this_thread::sleep_for(std::chrono::milliseconds{100});
    chessClock.stopBlack();
    std::this_thread::sleep_for(std::chrono::milliseconds{33});
    chessClock.stop();
    std::cout << chessClock.readWhiteTimeInMillis().count() << "\n";
    std::cout << chessClock.readBlackTimeInMillis().count() << "\n";
}