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

    std::vector<Position> Rook::getMovePattern(const Chessboard &board, Position from) const
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

    bool Rook::isMoved() const
    {
        return moved;
    }

    void Rook::setMoved(bool moved)
    {
        this->moved = moved;
    }

    std::vector<Direction> Rook::getMoveDirections() const
    {
        using namespace direction;
        std::vector<Direction> directions{n, e, s, w};
        return directions;
    }
}