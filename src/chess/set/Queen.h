#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"
#include "Color.h"

namespace chess
{
    class Queen : public ChessPiece
    {
    public:
        explicit Queen(Color);

        std::unique_ptr<ChessPiece> clone() const override;
    };
}

#endif