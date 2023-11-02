#include "Chessboard.h"

#include "Color.h"

namespace chess
{
    Chessboard::Chessboard()
    {
        Color color{Color::white};
        for (auto &row : grid)
            for (auto &square : row)
            {
                square.setColor(color);
                color = !color;
            }
    }

    void Chessboard::place(Position at, std::unique_ptr<ChessPiece> chessPiece)
    {
        getSquare(at).setChessPiece(std::move(chessPiece));
    }

    void Chessboard::move(Position from, Position to)
    {
        auto chessPiece = getSquare(from).getChessPiece();
        if (chessPiece)
            place(to, std::move(chessPiece));
    }

    Square &Chessboard::getSquare(Position at)
    {
        return grid.at(at.row).at(at.column);
    }
}