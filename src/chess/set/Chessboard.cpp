#include "Chessboard.h"

#include "Color.h"

namespace chess
{
    Chessboard::Chessboard(int numberOfRows, int numberOfColumns) : numberOfRows{numberOfRows}, numberOfColumns{numberOfColumns}
    {
        Color color{Color::white};
        for (auto rows = 0; rows < numberOfRows; rows++)
        {
            std::vector<Square> row;
            for (auto columns = 0; columns < numberOfColumns; columns++)
            {
                Square square{color};
                row.push_back(square);
                color = !color;
            }
            grid.push_back(row);
            color = !color;
        }
    }

    int Chessboard::getNumberOfRows() const
    {
        return numberOfRows;
    }

    int Chessboard::getNumberOfColumns() const
    {
        return numberOfColumns;
    }

    Square &Chessboard::getSquare(Position at)
    {
        return grid.at(at.row).at(at.column);
    }

    const Square &Chessboard::getSquareView(Position at) const
    {
        return grid.at(at.row).at(at.column);
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

    bool Chessboard::contains(Position position) const
    {
        return (0 <= position.row && position.row < numberOfRows) && (0 <= position.column && position.column < numberOfColumns);
    }
}