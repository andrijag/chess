#ifndef SQUARE_H
#define SQUARE_H

#include <memory>

#include "ChessPiece.h"
#include "Color.h"

namespace chess
{
    class Chessboard;

    class Square
    {
    private:
        Color color;
        std::unique_ptr<ChessPiece> chessPiece{nullptr};

    public:
        explicit Square(Color);
        ~Square() = default;

        Square(const Square &);
        Square &operator=(const Square &);

        Square(Square &&) = default;
        Square &operator=(Square &&) = default;

        Color getColor() const;
        ChessPiece *getChessPiece() const;
        bool isEmpty() const;

    private:
        friend Chessboard;
        std::unique_ptr<ChessPiece> getChessPieceOwnership();
        void setChessPiece(std::unique_ptr<ChessPiece>);
    };
}

#endif