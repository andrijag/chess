#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"
#include "Color.h"

namespace chess
{
    class Knight : public ChessPiece
    {
    public:
        explicit Knight(Color);

        std::unique_ptr<ChessPiece> clone() const override;
    };
}

#endif