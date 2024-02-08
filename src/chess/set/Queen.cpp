#include "Queen.h"

#include "RelativeValues.h"

namespace chess
{
    Queen::Queen(Color color) : ChessPiece{color, fischer::queenValue}
    {
    }

    std::unique_ptr<ChessPiece> Queen::clone() const
    {
        return createChessPiece<Queen>(color);
    }

    void Queen::accept(Visitor &visitor) const
    {
        visitor.visitQueen(color);
    }

    std::unordered_set<Position> Queen::getMovePattern(const Chessboard &board, Position from) const
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

    std::unordered_set<Direction> Queen::getMoveDirections() const
    {
        using namespace direction;
        std::unordered_set<Direction> directions{n, ne, e, se, s, sw, w, nw};
        return directions;
    }
}