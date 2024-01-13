#ifndef ROOK_H
#define ROOK_H

#include <memory>

#include "ChessPiece.h"
#include "Color.h"
#include "Visitor.h"

namespace chess
{
    class Rook : public ChessPiece
    {
    public:
        explicit Rook(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
    };
}

#endif