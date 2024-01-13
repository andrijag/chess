#include "Queen.h"

#include "RelativeValues.h"

namespace chess
{
    Queen::Queen(Color color) : ChessPiece{color, fischer::queenValue}
    {
    }

    std::unique_ptr<ChessPiece> Queen::clone() const
    {
        return createChessPiece<Queen>(color);
    }

    void Queen::accept(Visitor &visitor) const
    {
        visitor.visitQueen(color);
    }
}