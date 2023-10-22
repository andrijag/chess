#ifndef SQUARE_H
#define SQUARE_H

#include <memory>

#include "Color.h"

namespace chess
{
    class Chessboard;

    class Square
    {
    private:
        Color color;
        std::unique_ptr<int> chessPiece;

    private:
        friend Chessboard;
        void setColor(Color);
    };
}

#endif