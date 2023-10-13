#ifndef RUNNING_STATE_H
#define RUNNING_STATE_H

#include <chrono>

#include "StopwatchState.h"

namespace chessclock
{
    class Stopwatch;

    class RunningState : public StopwatchState
    {
    public:
        void start(Stopwatch &) override;
        void stop(Stopwatch &) override;
        std::chrono::milliseconds readTimeInMillis(const Stopwatch &) const override;
    };
}

#endif