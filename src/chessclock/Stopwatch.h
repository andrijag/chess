#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

namespace chessclock
{
    class Stopwatch
    {
    private:
        std::chrono::time_point<std::chrono::system_clock> startTime;
        std::chrono::milliseconds elapsedTime;
        bool isRunning;

    public:
        void start();
        void stop();
        std::chrono::milliseconds readTimeInMillis() const;
        void reset();
    };

    std::chrono::time_point<std::chrono::system_clock> getCurrentTime();
}

#endif