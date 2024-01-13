#include "Rook.h"

#include "RelativeValues.h"

namespace chess
{
    Rook::Rook(Color color) : ChessPiece{color, fischer::rookValue}
    {
    }

    std::unique_ptr<ChessPiece> Rook::clone() const
    {
        return createChessPiece<Rook>(color);
    }

    void Rook::accept(Visitor &visitor) const
    {
        visitor.visitRook(color);
    }
}