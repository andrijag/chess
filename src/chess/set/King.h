#ifndef KING_H
#define KING_H

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
    class King : public ChessPiece
    {
    public:
        explicit King(Color);

        Color getColor() const override;
        double getValue() const override;
        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
        std::unordered_set<Position> getMovePattern(const Chessboard &, Position) const override;

    private:
        std::unordered_set<Direction> getMoveDirections() const;

    private:
        Color color;
        double value;
    };
}

#endif