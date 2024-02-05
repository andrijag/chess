#ifndef GAME_STATUS_H
#define GAME_STATUS_H

namespace chess
{
    enum class GameStatus
    {
        notPlaying,
        playing,
        whiteCheckmates,
        blackCheckmates,
        stalemate
    };
}

#endif