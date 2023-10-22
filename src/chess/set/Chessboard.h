#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <array>

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
    };
}

#endif