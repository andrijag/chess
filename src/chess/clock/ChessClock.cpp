#include "ChessClock.h"

namespace chess
{
    void ChessClock::start()
    {
        stopBlack();
    }

    void ChessClock::stopWhite()
    {
        whiteStopwatch.stop();
        blackStopwatch.start();
    }

    void ChessClock::stopBlack()
    {
        whiteStopwatch.start();
        blackStopwatch.stop();
    }

    void ChessClock::stop()
    {
        whiteStopwatch.stop();
        blackStopwatch.stop();
    }

    Milliseconds ChessClock::readWhiteTimeInMillis() const
    {
        return whiteStopwatch.readTimeInMillis();
    }

    Milliseconds ChessClock::readBlackTimeInMillis() const
    {
        return blackStopwatch.readTimeInMillis();
    }

    void ChessClock::reset()
    {
        whiteStopwatch.reset();
        blackStopwatch.reset();
    }
}