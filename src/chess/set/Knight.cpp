#include "Knight.h"

#include "RelativeValues.h"

namespace chess
{
    Knight::Knight(Color color) : color{color}, value{fischer::knightValue}
    {
    }

    Color Knight::getColor() const
    {
        return color;
    }

    double Knight::getValue() const
    {
        return value;
    }

    std::unique_ptr<ChessPiece> Knight::clone() const
    {
        return createChessPiece<Knight>(color);
    }

    void Knight::accept(Visitor &visitor) const
    {
        visitor.visitKnight(color);
    }

    std::unordered_set<Position> Knight::getMovePattern(const Chessboard &board, Position from) const
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

    std::unordered_set<Direction> Knight::getMoveDirections() const
    {
        using namespace direction;
        std::unordered_set<Direction> directions{
            n + nw, n + ne,
            e + ne, e + se,
            s + se, s + sw,
            w + sw, w + nw};
        return directions;
    }
}