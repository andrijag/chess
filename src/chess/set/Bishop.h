#ifndef BISHOP_H
#define BISHOP_H

#include <memory>

#include "ChessPiece.h"
#include "Color.h"
#include "Visitor.h"

namespace chess
{
    class Bishop : public ChessPiece
    {
    public:
        explicit Bishop(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
    };
}

#endif