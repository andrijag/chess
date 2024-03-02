#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <memory>
#include <unordered_set>

#include "Color.h"
#include "Direction.h"
#include "Position.h"

namespace chess
{
    class Chessboard;
    class Visitor;

    class ChessPiece
    {
    public:
        virtual ~ChessPiece() = default;

    public:
        virtual Color getColor() const = 0;
        virtual double getValue() const = 0;
        virtual std::unique_ptr<ChessPiece> clone() const = 0;
        virtual void accept(Visitor &) const = 0;
        virtual std::unordered_set<Position> getMovePattern(const Chessboard &, Position) const = 0;

    protected:
        bool isOwnPieceAt(const Chessboard &, Position) const;
        bool isEnemyPieceAt(const Chessboard &, Position) const;
    };

    template <class T>
    std::unique_ptr<T> createChessPiece(Color color)
    {
        return std::make_unique<T>(color);
    }
}

#endif