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

    std::vector<Position> Pawn::getMovePattern(const Chessboard &board, Position from) const
    {
        std::vector<Position> movePattern;
        auto moveDirection = getMoveDirection(color);
        auto move = from + moveDirection;
        if (board.contains(move) && board.isEmptyAt(move))
        {
            movePattern.push_back(move);
            move += moveDirection;
            if (firstMove && board.contains(move) && board.isEmptyAt(move))
                movePattern.push_back(move);
        }
        for (auto captureDirection : getCaptureDirections(color))
        {
            auto capture = from + captureDirection;
            if (board.contains(capture) && isEnemy(board, capture))
                movePattern.push_back(capture);
        }
        return movePattern;
    }

    bool Pawn::isFirstMove() const
    {
        return firstMove;
    }

    void Pawn::setFirstMove(bool firstMove)
    {
        this->firstMove = firstMove;
    }

    Direction Pawn::getMoveDirection(Color color) const
    {
        return (color == Color::white) ? direction::n : direction::s;
    }

    std::vector<Direction> Pawn::getCaptureDirections(Color color) const
    {
        auto moveDirection = getMoveDirection(color);
        using namespace direction;
        std::vector<Direction> captureDirections{moveDirection + e, moveDirection + w};
        return captureDirections;
    }
}