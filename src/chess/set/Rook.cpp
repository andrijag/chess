#include "Rook.h"

#include "RelativeValues.h"

namespace chess
{
    Rook::Rook(Color color) : ChessPiece{color, fisher::rookValue}
    {
    }

    std::unique_ptr<ChessPiece> Rook::clone() const
    {
        return std::make_unique<Rook>(color);
    }
}