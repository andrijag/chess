#include "ChessPiece.h"

#include "Chessboard.h"

namespace chess
{
    bool ChessPiece::isOwnPieceAt(const Chessboard &board, Position position) const
    {
        auto chessPiece = board.getChessPieceAt(position);
        return chessPiece && chessPiece->getColor() == getColor();
    }

    bool ChessPiece::isEnemyPieceAt(const Chessboard &board, Position position) const
    {
        auto chessPiece = board.getChessPieceAt(position);
        return chessPiece && chessPiece->getColor() != getColor();
    }
}