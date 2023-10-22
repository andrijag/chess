#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"
#include "Color.h"

namespace chess
{
    class Pawn : public ChessPiece
    {
    public:
        Pawn(Color);
    };
}

#endif