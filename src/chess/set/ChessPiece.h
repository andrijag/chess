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
    protected:
        Color color;
        double value;

    protected:
        ChessPiece(Color, double);

    public:
        virtual ~ChessPiece() = default;

    protected:
        ChessPiece(const ChessPiece &) = default;
        ChessPiece &operator=(const ChessPiece &) = default;
        ChessPiece(ChessPiece &&) = default;
        ChessPiece &operator=(ChessPiece &&) = default;

    public:
        virtual std::unique_ptr<ChessPiece> clone() const = 0;
        Color getColor() const;
        double getValue() const;
        virtual void accept(Visitor &) const = 0;
        virtual std::unordered_set<Position> getMovePattern(const Chessboard &, Position) const = 0;

    protected:
        bool isOwnPiece(const Chessboard &, Position) const;
        bool isEnemyPiece(const Chessboard &, Position) const;
    };

    template <class T>
    std::unique_ptr<T> createChessPiece(Color color)
    {
        return std::make_unique<T>(color);
    }
}

#endif