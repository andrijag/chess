#ifndef CHESS_CLOCK_H
#define CHESS_CLOCK_H

#include <chrono>

#include "Stopwatch.h"

namespace chessclock
{
    class ChessClock
    {
    private:
        Stopwatch whiteStopwatch;
        Stopwatch blackStopwatch;

    public:
        void start();
        void stopWhite();
        void stopBlack();
        void stop();
        std::chrono::milliseconds readWhiteTimeInMillis() const;
        std::chrono::milliseconds readBlackTimeInMillis() const;
        void reset();
    };
}

#endif