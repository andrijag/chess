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
        elapsedTime = readTime();
        isRunning = false;
    }

    Milliseconds Stopwatch::readTime() const
    {
        auto totalElapsedTime = elapsedTime;
        if (isRunning)
            totalElapsedTime += getDuration(startTime, getCurrentTime());
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

    Milliseconds getDuration(TimePoint t1, TimePoint t2)
    {
        return std::chrono::duration_cast<Milliseconds>(t2 - t1);
    }
}