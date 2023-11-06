#include "Queen.h"

#include "RelativeValues.h"

namespace chess
{
    Queen::Queen(Color color) : ChessPiece{color, fisher::queenValue}
    {
    }

    std::unique_ptr<ChessPiece> Queen::clone() const
    {
        return std::make_unique<Queen>(color);
    }
}