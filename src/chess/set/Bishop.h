#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"
#include "Color.h"

namespace chess
{
    class Bishop : public ChessPiece
    {
    public:
        explicit Bishop(Color);

        std::unique_ptr<ChessPiece> clone() const override;
    };
}

#endif