#include "Pawn.h"

#include "RelativeValues.h"

namespace chess
{
    Pawn::Pawn(Color color) : ChessPiece{color, fisher::pawnValue}
    {
    }
}