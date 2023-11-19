#include "Square.h"

namespace chess
{
    Square::Square(const Square &square) : color{square.color}
    {
        if (square.chessPiece)
            chessPiece = square.chessPiece->clone();
    }

    Square &Square::operator=(const Square &square)
    {
        color = square.color;
        if (square.chessPiece)
            chessPiece = square.chessPiece->clone();
        return *this;
    }

    ChessPiece *Square::getChessPiece() const
    {
        return chessPiece.get();
    }

    void Square::setColor(Color color)
    {
        this->color = color;
    }

    void Square::setChessPiece(std::unique_ptr<ChessPiece> chessPiece)
    {
        this->chessPiece = std::move(chessPiece);
    }

    std::unique_ptr<ChessPiece> Square::getChessPieceOwnership()
    {
        return std::move(chessPiece);
    }
}