#include "Rook.h"

#include "RelativeValues.h"

namespace chess
{
    Rook::Rook(Color color) : ChessPiece{color, fischer::rookValue}
    {
    }

    std::unique_ptr<ChessPiece> Rook::clone() const
    {
        return createChessPiece<Rook>(color);
    }

    void Rook::accept(Visitor &visitor) const
    {
        visitor.visitRook(color);
    }

    std::unordered_set<Position> Rook::getMovePattern(const Chessboard &board, Position from) const
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

    std::unordered_set<Direction> Rook::getMoveDirections() const
    {
        using namespace direction;
        std::unordered_set<Direction> directions{n, e, s, w};
        return directions;
    }
}