#include "ChessPiece.h"

#include "Chessboard.h"

namespace chess
{
    ChessPiece::ChessPiece(Color color, double value) : color{color}, value{value}
    {
    }

    Color ChessPiece::getColor() const
    {
        return color;
    }

    bool ChessPiece::isFriendly(const Chessboard &board, Position at) const
    {
        auto chessPiece = board.getSquareView(at).getChessPiece();
        return chessPiece && chessPiece->getColor() == color;
    }

    bool ChessPiece::isEnemy(const Chessboard &board, Position at) const
    {
        auto chessPiece = board.getSquareView(at).getChessPiece();
        return chessPiece && chessPiece->getColor() != color;
    }
}