#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <array>
#include <memory>

#include "ChessPiece.h"
#include "Position.h"
#include "Square.h"

namespace chess
{
    class Chessboard
    {
    private:
        static constexpr int numberOfRows{8};
        static constexpr int numberOfColumns{8};
        std::array<std::array<Square, numberOfColumns>, numberOfRows> grid;

    public:
        Chessboard();
        void place(Position, std::unique_ptr<ChessPiece>);
        void move(Position, Position);

    private:
        Square &getSquare(Position);
    };
}

#endif