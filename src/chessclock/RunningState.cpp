#include "RunningState.h"

#include <memory>

#include "StoppedState.h"

namespace chessclock
{
    void RunningState::start(Stopwatch &stopwatch)
    {
    }

    void RunningState::stop(Stopwatch &stopwatch)
    {
        setElapsedTime(stopwatch, readTimeInMillis(stopwatch));
        changeState(stopwatch, std::make_unique<StoppedState>());
    }

    std::chrono::milliseconds RunningState::readTimeInMillis(const Stopwatch &stopwatch) const
    {
        return getElapsedTime(stopwatch) + std::chrono::duration_cast<std::chrono::milliseconds>(getCurrentTime() - getStartTime(stopwatch));
    }
}