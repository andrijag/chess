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

    std::vector<Position> Queen::getMovePattern(const Chessboard &board, Position from) const
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
            if (board.contains(move) && isEnemyPiece(board, move))
                movePattern.push_back(move);
        }
        return movePattern;
    }

    std::vector<Direction> Queen::getMoveDirections() const
    {
        using namespace direction;
        std::vector<Direction> directions{n, ne, e, se, s, sw, w, nw};
        return directions;
    }
}