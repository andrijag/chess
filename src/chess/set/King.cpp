#include "King.h"

#include "RelativeValues.h"

namespace chess
{
    King::King(Color color) : ChessPiece{color, fisher::kingValue}
    {
    }

    std::unique_ptr<ChessPiece> King::clone() const
    {
        return std::make_unique<King>(this->color);
    }
}