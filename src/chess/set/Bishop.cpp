#include "Bishop.h"

#include "RelativeValues.h"

namespace chess
{
    Bishop::Bishop(Color color) : ChessPiece{color, fischer::bishopValue}
    {
    }

    std::unique_ptr<ChessPiece> Bishop::clone() const
    {
        return createChessPiece<Bishop>(color);
    }

    void Bishop::accept(Visitor &visitor) const
    {
        visitor.visitBishop(color);
    }

    std::vector<Position> Bishop::getMovePattern(const Chessboard &board, Position from) const
    {
        std::vector<Position> movePattern;
        for (auto direction : getMoveDirections())
        {
            auto move = from + direction;
            while (board.contains(move) && board.isEmptyAt(move))
            {
                movePattern.push_back(move);
                move += direction;
            }
            if (board.contains(move) && isEnemy(board, move))
                movePattern.push_back(move);
        }
        return movePattern;
    }

    std::vector<Direction> Bishop::getMoveDirections() const
    {
        using namespace direction;
        std::vector<Direction> directions{ne, se, sw, nw};
        return directions;
    }
}