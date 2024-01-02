#ifndef VISITOR_H
#define VISITOR_H

#include "Color.h"

namespace chess
{
    class Visitor
    {
    public:
        virtual ~Visitor() = default;

        virtual void visitEmptySquare() = 0;
        virtual void visitPawn(Color) = 0;
        virtual void visitKnight(Color) = 0;
        virtual void visitBishop(Color) = 0;
        virtual void visitRook(Color) = 0;
        virtual void visitQueen(Color) = 0;
        virtual void visitKing(Color) = 0;
    };
}

#endif