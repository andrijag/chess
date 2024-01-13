#ifndef PAWN_H
#define PAWN_H

#include <memory>

#include "ChessPiece.h"
#include "Color.h"
#include "Visitor.h"

namespace chess
{
    class Pawn : public ChessPiece
    {
    public:
        explicit Pawn(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
    };
}

#endif