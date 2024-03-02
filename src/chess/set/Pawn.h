#ifndef PAWN_H
#define PAWN_H

#include <memory>
#include <unordered_set>

#include "Chessboard.h"
#include "ChessPiece.h"
#include "Color.h"
#include "Direction.h"
#include "Position.h"
#include "Visitor.h"

namespace chess
{
    class Pawn : public ChessPiece
    {
    public:
        explicit Pawn(Color);

        Color getColor() const override;
        double getValue() const override;
        bool isFirstMove() const;
        void setFirstMove(bool);
        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
        std::unordered_set<Position> getMovePattern(const Chessboard &, Position) const override;

    private:
        Direction getMoveDirection(Color) const;
        std::unordered_set<Direction> getCaptureDirections(Color) const;

    private:
        Color color;
        double value;
        bool firstMove{true};
    };
}

#endif