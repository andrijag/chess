#include "King.h"

#include "RelativeValues.h"

namespace chess
{
    King::King(Color color) : ChessPiece{color, fischer::kingValue}
    {
    }

    std::unique_ptr<ChessPiece> King::clone() const
    {
        return createChessPiece<King>(color);
    }

    void King::accept(Visitor &visitor) const
    {
        visitor.visitKing(color);
    }

    std::unordered_set<Position> King::getMovePattern(const Chessboard &board, Position from) const
    {
        std::unordered_set<Position> movePattern;
        for (auto direction : getMoveDirections())
        {
            auto move = from + direction;
            if (board.contains(move) && !isOwnPieceAt(board, move))
                movePattern.insert(move);
        }
        return movePattern;
    }

    std::unordered_set<Direction> King::getMoveDirections() const
    {
        using namespace direction;
        std::unordered_set<Direction> directions{n, ne, e, se, s, sw, w, nw};
        return directions;
    }
}