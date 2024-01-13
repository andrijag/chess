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

    Milliseconds Stopwatch::readTimeInMillis() const
    {
        auto totalElapsedTime = elapsedTime;
        if (isRunning)
            totalElapsedTime += std::chrono::duration_cast<Milliseconds>(getCurrentTime() - startTime);
        return totalElapsedTime;
    }

    void Stopwatch::reset()
    {
        elapsedTime = Milliseconds{0};
        isRunning = false;
    }

    TimePoint getCurrentTime()
    {
        return std::chrono::system_clock::now();
    }
}