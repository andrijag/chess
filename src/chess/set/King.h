#ifndef KING_H
#define KING_H

#include "ChessPiece.h"
#include "Color.h"

namespace chess
{
    class King : public ChessPiece
    {
    public:
        explicit King(Color);

        std::unique_ptr<ChessPiece> clone() const override;
    };
}

#endif