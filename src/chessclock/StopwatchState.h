#ifndef STOPWATCH_STATE_H
#define STOPWATCH_STATE_H

#include <chrono>
#include <memory>

namespace chessclock
{
    class Stopwatch;

    class StopwatchState
    {
    public:
        virtual ~StopwatchState() = default;
        virtual void start(Stopwatch *) = 0;
        virtual void stop(Stopwatch *) = 0;
        virtual std::chrono::milliseconds readTimeInMillis(const Stopwatch *) const = 0;

    protected:
        std::chrono::time_point<std::chrono::system_clock> getStartTime(const Stopwatch *) const;
        void setStartTime(Stopwatch *, std::chrono::time_point<std::chrono::system_clock>);
        std::chrono::milliseconds getElapsedTime(const Stopwatch *) const;
        void setElapsedTime(Stopwatch *, std::chrono::milliseconds);
        void changeState(Stopwatch *, std::unique_ptr<StopwatchState>);
    };

    std::chrono::time_point<std::chrono::system_clock> getCurrentTime();
}

#endif