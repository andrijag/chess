#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

namespace chess
{
    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
    using Milliseconds = std::chrono::milliseconds;

    class Stopwatch
    {
    private:
        TimePoint startTime;
        Milliseconds elapsedTime{0};
        bool isRunning{false};

    public:
        void start();
        void stop();
        Milliseconds readTimeInMillis() const;
        void reset();
    };

    TimePoint getCurrentTime();
}

#endif