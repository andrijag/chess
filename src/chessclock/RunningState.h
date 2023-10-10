#ifndef RUNNING_STATE_H
#define RUNNING_STATE_H

#include "StopwatchState.h"

namespace chessclock
{
    class RunningState : public StopwatchState
    {
    public:
        void start(Stopwatch *stopwatch) override;
        void stop(Stopwatch *stopwatch) override;
        std::chrono::milliseconds readTimeInMillis(const Stopwatch *stopwatch) override;
    };
}

#endif