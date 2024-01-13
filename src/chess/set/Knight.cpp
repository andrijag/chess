#include "Knight.h"

#include "RelativeValues.h"

namespace chess
{
    Knight::Knight(Color color) : ChessPiece{color, fischer::knightValue}
    {
    }

    std::unique_ptr<ChessPiece> Knight::clone() const
    {
        return createChessPiece<Knight>(color);
    }

    void Knight::accept(Visitor &visitor) const
    {
        visitor.visitKnight(color);
    }
}