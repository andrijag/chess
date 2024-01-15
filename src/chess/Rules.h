#ifndef RULES_H
#define RULES_H

#include <memory>

#include "Color.h"
#include "MoveStrategy.h"
#include "Visitor.h"

namespace chess
{
    class Rules : public Visitor
    {
    private:
        std::unique_ptr<MoveStrategy> moveStrategy;

    public:
        void visitEmptySquare() override;
        void visitPawn(Color) override;
        void visitKnight(Color) override;
        void visitBishop(Color) override;
        void visitRook(Color) override;
        void visitQueen(Color) override;
        void visitKing(Color) override;
    };
}

#endif