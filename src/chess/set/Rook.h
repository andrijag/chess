#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"
#include "Color.h"

namespace chess
{
    class Rook : public ChessPiece
    {
    public:
        explicit Rook(Color);

        std::unique_ptr<ChessPiece> clone() const override;
    };
}

#endif