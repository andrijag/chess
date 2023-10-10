#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>
#include <memory>

#include "StopwatchState.h"

class Stopwatch
{
private:
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::milliseconds elapsedTime;
    std::unique_ptr<StopwatchState> state;

public:
    Stopwatch();
    void start();
    void stop();
    std::chrono::milliseconds readTimeInMillis() const;
    void reset();

private:
    friend class StopwatchState;
    std::chrono::time_point<std::chrono::system_clock> getStartTime() const;
    void setStartTime(std::chrono::time_point<std::chrono::system_clock>);
    std::chrono::milliseconds getElapsedTime() const;
    void setElapsedTime(std::chrono::milliseconds);
    void changeState(std::unique_ptr<StopwatchState>);
};

#endif