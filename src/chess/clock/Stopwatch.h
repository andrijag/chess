#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

namespace chess
{
    class Stopwatch
    {
    private:
        std::chrono::time_point<std::chrono::system_clock> startTime{std::chrono::system_clock::now()};
        std::chrono::milliseconds elapsedTime{std::chrono::milliseconds::zero()};
        bool isRunning{false};

    public:
        void start();
        void stop();
        std::chrono::milliseconds readTimeInMillis() const;
        void reset();
    };

    std::chrono::time_point<std::chrono::system_clock> getCurrentTime();
}

#endif