#include "Chessboard.h"

#include "Color.h"

namespace chess
{
    Chessboard::Chessboard()
    {
        Color color{Color::white};
        for (auto &row : grid)
        {
            for (auto &square : row)
            {
                square.setColor(color);
                color = !color;
            }
        }
    }
}