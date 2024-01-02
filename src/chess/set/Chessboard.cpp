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
        auto chessPiece = getSquare(from).getChessPieceOwnership();
        if (chessPiece)
            place(to, std::move(chessPiece));
    }

    Square &Chessboard::getSquare(Position at)
    {
        return grid.at(at.row).at(at.column);
    }

    const Square &Chessboard::getSquareView(Position at) const
    {
        return grid.at(at.row).at(at.column);
    }

    bool Chessboard::contains(Position position) const
    {
        return (0 <= position.row && position.row < numberOfRows) && (0 <= position.column && position.column < numberOfColumns);
    }
}