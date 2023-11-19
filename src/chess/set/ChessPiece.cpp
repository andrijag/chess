#include "ChessPiece.h"

namespace chess
{
    ChessPiece::ChessPiece(Color color, double value) : color{color}, value{value}
    {
    }

    Color ChessPiece::getColor() const
    {
        return color;
    }
}