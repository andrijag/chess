#include "Stopwatch.h"

namespace chess
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
        auto totalElapsedTime = elapsedTime;
        if (isRunning)
            totalElapsedTime += std::chrono::duration_cast<std::chrono::milliseconds>(getCurrentTime() - startTime);
        return totalElapsedTime;
    }

    void Stopwatch::reset()
    {
        startTime = std::chrono::system_clock::now();
        elapsedTime = std::chrono::milliseconds::zero();
        isRunning = false;
    }

    std::chrono::time_point<std::chrono::system_clock> getCurrentTime()
    {
        return std::chrono::system_clock::now();
    }
}