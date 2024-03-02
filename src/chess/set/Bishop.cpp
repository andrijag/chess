#include "Bishop.h"

#include "RelativeValues.h"

namespace chess
{
    Bishop::Bishop(Color color) : color{color}, value{fischer::bishopValue}
    {
    }

    Color Bishop::getColor() const
    {
        return color;
    }

    double Bishop::getValue() const
    {
        return value;
    }

    std::unique_ptr<ChessPiece> Bishop::clone() const
    {
        return createChessPiece<Bishop>(color);
    }

    void Bishop::accept(Visitor &visitor) const
    {
        visitor.visitBishop(color);
    }

    std::unordered_set<Position> Bishop::getMovePattern(const Chessboard &board, Position from) const
    {
        std::unordered_set<Position> movePattern;
        for (auto direction : getMoveDirections())
        {
            auto move = from + direction;
            while (board.contains(move) && board.isEmptyAt(move))
            {
                movePattern.insert(move);
                move += direction;
            }
            if (board.contains(move) && isEnemyPieceAt(board, move))
                movePattern.insert(move);
        }
        return movePattern;
    }

    std::unordered_set<Direction> Bishop::getMoveDirections() const
    {
        using namespace direction;
        std::unordered_set<Direction> directions{ne, se, sw, nw};
        return directions;
    }
}