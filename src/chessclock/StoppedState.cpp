#include "StoppedState.h"

#include "RunningState.h"

namespace chessclock
{
    void StoppedState::start(Stopwatch *stopwatch)
    {
        setStartTime(stopwatch, getCurrentTime());
        changeState(stopwatch, std::make_unique<RunningState>());
    }

    void StoppedState::stop(Stopwatch *stopwatch)
    {
    }

    std::chrono::milliseconds StoppedState::readTimeInMillis(const Stopwatch *stopwatch)
    {
        return getElapsedTime(stopwatch);
    }
}