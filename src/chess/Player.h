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
    private:
        Color color;

    public:
        explicit Player(Color);

        Color getColor() const;
        void stopTime(ChessClock &) const;
        bool isOwnPiece(Chessboard &, Position) const;
    };
}

#endif