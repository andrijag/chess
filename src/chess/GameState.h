#ifndef GAME_STATE_H
#define GAME_STATE_H

namespace chess
{
    enum class GameState
    {
        playing,
        whiteCheckmates,
        blackCheckmates,
        stalemate
    };
}

#endif