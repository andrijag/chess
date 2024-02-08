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

    double ChessPiece::getValue() const
    {
        return value;
    }

    bool ChessPiece::isOwnPieceAt(const Chessboard &board, Position position) const
    {
        auto chessPiece = board.getChessPieceAt(position);
        return chessPiece && chessPiece->getColor() == color;
    }

    bool ChessPiece::isEnemyPieceAt(const Chessboard &board, Position position) const
    {
        auto chessPiece = board.getChessPieceAt(position);
        return chessPiece && chessPiece->getColor() != color;
    }
}