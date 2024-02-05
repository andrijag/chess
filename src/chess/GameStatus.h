#ifndef GAME_STATUS_H
#define GAME_STATUS_H

namespace chess
{
    enum class GameStatus
    {
        playing,
        whiteCheckmates,
        blackCheckmates,
        stalemate
    };
}

#endif