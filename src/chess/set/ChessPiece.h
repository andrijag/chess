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

        ChessPiece(const ChessPiece &) = delete;
        ChessPiece &operator=(const ChessPiece &) = delete;

        ChessPiece(ChessPiece &&) = delete;
        ChessPiece &operator=(ChessPiece &&) = delete;

        virtual std::unique_ptr<ChessPiece> clone() const = 0;
    };

    template <typename T>
    std::unique_ptr<T> createChessPiece(Color color)
    {
        return std::make_unique<T>(color);
    }
}

#endif