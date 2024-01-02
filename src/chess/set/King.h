#ifndef KING_H
#define KING_H

#include "ChessPiece.h"
#include "Color.h"
#include "Visitor.h"

namespace chess
{
    class King : public ChessPiece
    {
    public:
        explicit King(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
    };
}

#endif