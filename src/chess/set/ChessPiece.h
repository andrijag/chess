#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <memory>

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

        virtual std::unique_ptr<ChessPiece> clone() const = 0;
    };
}

#endif