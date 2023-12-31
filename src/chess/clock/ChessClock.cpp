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

    std::chrono::milliseconds ChessClock::readWhiteTimeInMillis() const
    {
        return whiteStopwatch.readTimeInMillis();
    }

    std::chrono::milliseconds ChessClock::readBlackTimeInMillis() const
    {
        return blackStopwatch.readTimeInMillis();
    }

    void ChessClock::reset()
    {
        whiteStopwatch.reset();
        blackStopwatch.reset();
    }
}