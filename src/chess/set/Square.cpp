#include "Square.h"

namespace chess
{
    Square::Square(Color color) : color{color}
    {
    }

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

    Color Square::getColor() const
    {
        return color;
    }

    ChessPiece *Square::getChessPiece()
    {
        return chessPiece.get();
    }

    const ChessPiece *Square::getChessPieceView() const
    {
        return chessPiece.get();
    }

    bool Square::isEmpty() const
    {
        return chessPiece == nullptr;
    }

    void Square::accept(Visitor &visitor) const
    {
        if (isEmpty())
            visitor.visitEmptySquare();
        else
            chessPiece->accept(visitor);
    }

    std::unique_ptr<ChessPiece> Square::getChessPieceOwnership()
    {
        return std::move(chessPiece);
    }

    void Square::setChessPiece(std::unique_ptr<ChessPiece> chessPiece)
    {
        this->chessPiece = std::move(chessPiece);
    }
}