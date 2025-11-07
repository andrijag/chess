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

    Milliseconds ChessClock::readWhiteTime() const
    {
        return whiteStopwatch.readTime();
    }

    Milliseconds ChessClock::readBlackTime() const
    {
        return blackStopwatch.readTime();
    }

    void ChessClock::reset()
    {
        whiteStopwatch.reset();
        blackStopwatch.reset();
    }
}