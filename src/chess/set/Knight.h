#ifndef KNIGHT_H
#define KNIGHT_H

#include <memory>

#include "ChessPiece.h"
#include "Color.h"
#include "Visitor.h"

namespace chess
{
    class Knight : public ChessPiece
    {
    public:
        explicit Knight(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
    };
}

#endif