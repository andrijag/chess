#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
#include <memory>

#include "ChessPiece.h"
#include "Position.h"
#include "Square.h"

namespace chess
{
    class Chessboard
    {
    private:
        const int numberOfRows;
        const int numberOfColumns;
        std::vector<std::vector<Square>> grid;

    public:
        Chessboard(int numberOfRows = 8, int numberOfColumns = 8);

        int getNumberOfRows() const;
        int getNumberOfColumns() const;
        Square &getSquare(Position);
        const Square &getSquareView(Position) const;
        void place(Position, std::unique_ptr<ChessPiece>);
        void move(Position, Position);
        bool contains(Position) const;
    };
}

#endif