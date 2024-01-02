#include "Bishop.h"

#include "RelativeValues.h"

namespace chess
{
    Bishop::Bishop(Color color) : ChessPiece{color, fischer::bishopValue}
    {
    }

    std::unique_ptr<ChessPiece> Bishop::clone() const
    {
        return std::make_unique<Bishop>(color);
    }

    void Bishop::accept(Visitor &visitor) const
    {
        visitor.visitBishop(color);
    }
}