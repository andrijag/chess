#include "King.h"

#include "RelativeValues.h"

namespace chess
{
    King::King(Color color) : ChessPiece{color, fischer::kingValue}
    {
    }

    std::unique_ptr<ChessPiece> King::clone() const
    {
        return createChessPiece<King>(color);
    }

    void King::accept(Visitor &visitor) const
    {
        visitor.visitKing(color);
    }

    bool King::isMoved() const
    {
        return moved;
    }

    void King::setMoved(bool moved)
    {
        this->moved = moved;
    }
}