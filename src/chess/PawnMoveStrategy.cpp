#include "PawnMoveStrategy.h"

#include "Direction.h"
#include "Move.h"

namespace chess
{
    std::vector<std::unique_ptr<MoveCommand>>
    PawnMoveStrategy::getMovePattern(Chessboard &board, Position source) const
    {
        std::vector<std::unique_ptr<MoveCommand>> movePattern;
        auto moveDirection = getMoveDirection(board.getSquareView(source).getChessPiece()->getColor());
        auto destination = source + moveDirection;
        if (board.contains(destination) && board.getSquareView(destination).isEmpty())
            movePattern.push_back(std::make_unique<Move>(board, source, destination));
        for (auto captureDirection : getCaptureDirections(moveDirection))
            if (board.contains(destination) && board.getSquareView(destination).getChessPiece()->getColor() != board.getSquareView(source).getChessPiece()->getColor())
                movePattern.push_back(std::make_unique<Move>(board, source, destination));
        return movePattern;
    }

    Direction PawnMoveStrategy::getMoveDirection(Color color) const
    {
        return (color == Color::white) ? direction::n : direction::s;
    }

    std::vector<Direction> PawnMoveStrategy::getCaptureDirections(Direction moveDirection) const
    {
        using namespace direction;
        std::vector<Direction> captureDirections{moveDirection + e, moveDirection + w};
        return captureDirections;
    }
}