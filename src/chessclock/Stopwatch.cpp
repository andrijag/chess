#include "Stopwatch.h"

namespace chessclock
{
    void Stopwatch::start()
    {
        if (isRunning)
            return;
        startTime = getCurrentTime();
        isRunning = true;
    }

    void Stopwatch::stop()
    {
        if (!isRunning)
            return;
        elapsedTime = readTimeInMillis();
        isRunning = false;
    }

    std::chrono::milliseconds Stopwatch::readTimeInMillis() const
    {
        auto runningTime = elapsedTime;
        if (isRunning)
            runningTime += std::chrono::duration_cast<std::chrono::milliseconds>(getCurrentTime() - startTime);
        return runningTime;
    }

    void Stopwatch::reset()
    {
        startTime = std::chrono::time_point<std::chrono::system_clock>{};
        elapsedTime = std::chrono::milliseconds{};
        isRunning = false;
    }

    std::chrono::time_point<std::chrono::system_clock> getCurrentTime()
    {
        return std::chrono::system_clock::now();
    }
}