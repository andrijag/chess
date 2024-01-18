#include "KingMoveStrategy.h"

#include "Move.h"

namespace chess
{
    std::vector<std::unique_ptr<MoveCommand>>
    KingMoveStrategy::getMovePattern(Chessboard &board, Position source) const
    {
        std::vector<std::unique_ptr<MoveCommand>> movePattern;
        for (auto direction : getMoveDirections())
        {
            auto destination = source + direction;
            if (board.contains(destination))
                if (board.getSquareView(destination).isEmpty())
                    movePattern.push_back(std::make_unique<Move>(board, source, destination));
                else if (board.getSquareView(destination).getChessPiece()->getColor() != board.getSquareView(source).getChessPiece()->getColor())
                    movePattern.push_back(std::make_unique<Move>(board, source, destination));
        }
        return movePattern;
    }

    std::vector<Direction> KingMoveStrategy::getMoveDirections() const
    {
        using namespace direction;
        std::vector<Direction> directions{n, ne, e, se, s, sw, w, nw};
        return directions;
    }
}