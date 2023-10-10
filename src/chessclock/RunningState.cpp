#include "RunningState.h"

#include "StoppedState.h"

namespace chessclock
{
    void RunningState::start(Stopwatch *stopwatch)
    {
    }

    void RunningState::stop(Stopwatch *stopwatch)
    {
        setElapsedTime(stopwatch, readTimeInMillis(stopwatch));
        changeState(stopwatch, std::make_unique<StoppedState>());
    }

    std::chrono::milliseconds RunningState::readTimeInMillis(const Stopwatch *stopwatch)
    {
        return getElapsedTime(stopwatch) + std::chrono::duration_cast<std::chrono::milliseconds>(getCurrentTime() - getStartTime(stopwatch));
    }
}