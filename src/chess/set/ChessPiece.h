#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <memory>

#include "Color.h"

namespace chess
{
    class ChessPiece
    {
    protected:
        Color color;
        double value;

    public:
        ChessPiece(Color, double);
        virtual ~ChessPiece() = default;

    protected:
        ChessPiece(const ChessPiece &) = default;
        ChessPiece &operator=(const ChessPiece &) = default;

        ChessPiece(ChessPiece &&) = default;
        ChessPiece &operator=(ChessPiece &&) = default;

    public:
        virtual std::unique_ptr<ChessPiece> clone() const = 0;
        Color getColor() const;
    };

    template <typename T>
    std::unique_ptr<ChessPiece> createChessPiece(Color color)
    {
        return std::make_unique<T>(color);
    }
}

#endif