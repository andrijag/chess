#include "Pawn.h"

#include "RelativeValues.h"

namespace chess
{
    Pawn::Pawn(Color color) : ChessPiece{color, fisher::pawnValue}
    {
    }

    std::unique_ptr<ChessPiece> Pawn::clone() const
    {
        return std::make_unique<Pawn>(this->color);
    }
}