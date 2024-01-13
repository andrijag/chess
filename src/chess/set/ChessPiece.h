#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <memory>

#include "Color.h"

namespace chess
{
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
        virtual void accept(Visitor &) const = 0;
    };

    template <class T>
    std::unique_ptr<ChessPiece> createChessPiece(Color color)
    {
        return std::make_unique<T>(color);
    }
}

#endif