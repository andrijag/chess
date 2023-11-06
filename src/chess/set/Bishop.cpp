#include "Bishop.h"

#include "RelativeValues.h"

namespace chess
{
    Bishop::Bishop(Color color) : ChessPiece{color, fisher::bishopValue}
    {
    }

    std::unique_ptr<ChessPiece> Bishop::clone() const
    {
        return std::make_unique<Bishop>(color);
    }
}