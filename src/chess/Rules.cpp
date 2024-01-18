#include "Rules.h"

#include <memory>

#include "BishopMoveStrategy.h"
#include "KingMoveStrategy.h"
#include "KnightMoveStrategy.h"
#include "PawnMoveStrategy.h"
#include "RookMoveStrategy.h"
#include "QueenMoveStrategy.h"

namespace chess
{
    void Rules::visitEmptySquare()
    {
        moveStrategy = nullptr;
    }

    void Rules::visitPawn(Color)
    {
        moveStrategy = std::make_unique<PawnMoveStrategy>();
    }

    void Rules::visitKnight(Color)
    {
        moveStrategy = std::make_unique<KnightMoveStrategy>();
    }

    void Rules::visitBishop(Color)
    {
        moveStrategy = std::make_unique<BishopMoveStrategy>();
    }

    void Rules::visitRook(Color)
    {
        moveStrategy = std::make_unique<RookMoveStrategy>();
    }

    void Rules::visitQueen(Color)
    {
        moveStrategy = std::make_unique<QueenMoveStrategy>();
    }

    void Rules::visitKing(Color)
    {
        moveStrategy = std::make_unique<KingMoveStrategy>();
    }
}