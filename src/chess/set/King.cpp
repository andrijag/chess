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

    std::vector<Position> King::getMovePattern(const Chessboard &board, Position from) const
    {
        std::vector<Position> movePattern;
        for (auto direction : getMoveDirections())
        {
            auto move = from + direction;
            if (board.contains(move) && !isFriendly(board, move))
                movePattern.push_back(move);
        }
        return movePattern;
    }

    bool King::isMoved() const
    {
        return moved;
    }

    void King::setMoved(bool moved)
    {
        this->moved = moved;
    }

    std::vector<Direction> King::getMoveDirections() const
    {
        using namespace direction;
        std::vector<Direction> directions{n, ne, e, se, s, sw, w, nw};
        return directions;
    }
}