#ifndef STOPPED_STATE_H
#define STOPPED_STATE_H

#include "StopwatchState.h"

class StoppedState : public StopwatchState
{
public:
    void start(Stopwatch *stopwatch) override;
    void stop(Stopwatch *stopwatch) override;
    std::chrono::milliseconds readTimeInMillis(const Stopwatch *stopwatch) override;
};

#endif