#ifndef KING_H
#define KING_H

#include <memory>

#include "ChessPiece.h"
#include "Color.h"
#include "Visitor.h"

namespace chess
{
    class King : public ChessPiece
    {
    private:
        bool moved{false};

    public:
        explicit King(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
        bool isMoved() const;
        void setMoved(bool);
    };
}

#endif