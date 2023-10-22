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
        std::unique_ptr<ChessPiece> chessPiece;

    public:
        Square() = default;
        ~Square() = default;

        Square(const Square &);
        Square &operator=(const Square &);

    private:
        friend Chessboard;
        void setColor(Color);
    };
}

#endif