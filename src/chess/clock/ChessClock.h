#ifndef CHESS_CLOCK_H
#define CHESS_CLOCK_H

#include <chrono>

#include "Stopwatch.h"

namespace chess
{
    class ChessClock
    {
    public:
        void start();
        void stopWhite();
        void stopBlack();
        void stop();
        Milliseconds readWhiteTimeInMillis() const;
        Milliseconds readBlackTimeInMillis() const;
        void reset();

    private:
        Stopwatch whiteStopwatch;
        Stopwatch blackStopwatch;
    };
}

#endif