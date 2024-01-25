#include "Knight.h"

#include "RelativeValues.h"

namespace chess
{
    Knight::Knight(Color color) : ChessPiece{color, fischer::knightValue}
    {
    }

    std::unique_ptr<ChessPiece> Knight::clone() const
    {
        return createChessPiece<Knight>(color);
    }

    void Knight::accept(Visitor &visitor) const
    {
        visitor.visitKnight(color);
    }

    std::vector<Position> Knight::getMovePattern(const Chessboard &board, Position from) const
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

    std::vector<Direction> Knight::getMoveDirections() const
    {
        using namespace direction;
        std::vector<Direction> directions{
            n + nw, n + ne,
            e + ne, e + se,
            s + se, s + sw,
            w + sw, w + nw};
        return directions;
    }
}