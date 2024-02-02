#include "Pawn.h"

#include "RelativeValues.h"

namespace chess
{
    Pawn::Pawn(Color color) : ChessPiece{color, fischer::pawnValue}
    {
    }

    std::unique_ptr<ChessPiece> Pawn::clone() const
    {
        auto clone = createChessPiece<Pawn>(color);
        clone->firstMove = firstMove;
        return clone;
    }

    bool Pawn::isFirstMove() const
    {
        return firstMove;
    }

    void Pawn::setFirstMove(bool firstMove)
    {
        this->firstMove = firstMove;
    }

    void Pawn::accept(Visitor &visitor) const
    {
        visitor.visitPawn(color);
    }

    std::unordered_set<Position> Pawn::getMovePattern(const Chessboard &board, Position from) const
    {
        std::unordered_set<Position> movePattern;
        auto moveDirection = getMoveDirection(color);
        auto move = from + moveDirection;
        if (board.contains(move) && board.isEmptyAt(move))
        {
            movePattern.insert(move);
            move += moveDirection;
            if (firstMove && board.contains(move) && board.isEmptyAt(move))
                movePattern.insert(move);
        }
        for (auto captureDirection : getCaptureDirections(color))
        {
            auto capture = from + captureDirection;
            if (board.contains(capture) && isEnemyPiece(board, capture))
                movePattern.insert(capture);
        }
        return movePattern;
    }

    Direction Pawn::getMoveDirection(Color color) const
    {
        return (color == Color::white) ? direction::n : direction::s;
    }

    std::unordered_set<Direction> Pawn::getCaptureDirections(Color color) const
    {
        auto moveDirection = getMoveDirection(color);
        using namespace direction;
        std::unordered_set<Direction> captureDirections{moveDirection + e, moveDirection + w};
        return captureDirections;
    }
}