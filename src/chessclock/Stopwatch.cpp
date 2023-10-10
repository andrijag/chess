#include "Stopwatch.h"

#include "StoppedState.h"

namespace chessclock
{
    Stopwatch::Stopwatch() : startTime{}, elapsedTime{}, state{std::make_unique<StoppedState>()} {}

    void Stopwatch::start() { state->start(this); }

    void Stopwatch::stop() { state->stop(this); }

    std::chrono::milliseconds Stopwatch::readTimeInMillis() const { return state->readTimeInMillis(this); }

    void Stopwatch::reset()
    {
        startTime = std::chrono::time_point<std::chrono::system_clock>{};
        elapsedTime = std::chrono::milliseconds{};
        state = std::make_unique<StoppedState>();
    }

    std::chrono::time_point<std::chrono::system_clock> Stopwatch::getStartTime() const
    {
        return this->startTime;
    }

    void Stopwatch::setStartTime(std::chrono::time_point<std::chrono::system_clock> startTime)
    {
        this->startTime = startTime;
    }

    std::chrono::milliseconds Stopwatch::getElapsedTime() const
    {
        return this->elapsedTime;
    }

    void Stopwatch::setElapsedTime(std::chrono::milliseconds elapsedTime)
    {
        this->elapsedTime = elapsedTime;
    }

    void Stopwatch::changeState(std::unique_ptr<StopwatchState> state)
    {
        this->state = std::move(state);
    }
}