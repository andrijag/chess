#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "Color.h"

namespace chess
{
    class ChessPiece
    {
    protected:
        Color color;
        double value;

    public:
        ChessPiece(Color, double);
        virtual ~ChessPiece() = default;
    };
}

#endif