#include "King.h"

#include "RelativeValues.h"

namespace chess
{
    King::King(Color color) : ChessPiece{color, fisher::kingValue}
    {
    }
}