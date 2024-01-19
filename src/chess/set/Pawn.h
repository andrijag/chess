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
    private:
        bool firstMove{true};

    public:
        explicit Pawn(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
        bool isFirstMove() const;
        void setFirstMove(bool);
    };
}

#endif