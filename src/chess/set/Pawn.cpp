#include "Pawn.h"

#include "RelativeValues.h"

namespace chess
{
    Pawn::Pawn(Color color) : ChessPiece{color, fischer::pawnValue}
    {
    }

    std::unique_ptr<ChessPiece> Pawn::clone() const
    {
        return createChessPiece<Pawn>(color);
    }

    void Pawn::accept(Visitor &visitor) const
    {
        visitor.visitPawn(color);
    }

    bool Pawn::isFirstMove() const
    {
        return firstMove;
    }

    void Pawn::setFirstMove(bool firstMove)
    {
        this->firstMove = firstMove;
    }
}