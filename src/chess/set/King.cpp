#include "King.h"

#include "RelativeValues.h"

namespace chess
{
    King::King(Color color) : ChessPiece{color, fischer::kingValue}
    {
    }

    std::unique_ptr<ChessPiece> King::clone() const
    {
        return std::make_unique<King>(color);
    }

    void King::accept(Visitor &visitor) const
    {
        visitor.visitKing(color);
    }
}