#ifndef PLAYER_H
#define PLAYER_H

#include "Chessboard.h"
#include "ChessClock.h"
#include "Color.h"
#include "Position.h"

namespace chess
{
    class Player
    {
    public:
        explicit Player(Color);

        Color getColor() const;
        void stopTime(ChessClock &) const;
        bool isOwnPieceAt(const Chessboard &, Position) const;

    private:
        Color color;
    };
}

#endif