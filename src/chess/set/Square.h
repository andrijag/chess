#ifndef SQUARE_H
#define SQUARE_H

#include <memory>

#include "ChessPiece.h"
#include "Color.h"
#include "Visitable.h"
#include "Visitor.h"

namespace chess
{
    class Square : public Visitable
    {
    public:
        explicit Square(Color);
        ~Square() = default;
        Square(const Square &);
        Square &operator=(const Square &);
        Square(Square &&) = default;
        Square &operator=(Square &&) = default;

        Color getColor() const;
        ChessPiece *getChessPiece();
        const ChessPiece *getChessPieceView() const;
        bool isEmpty() const;
        void accept(Visitor &) const override;

    private:
        friend Chessboard;
        std::unique_ptr<ChessPiece> getChessPieceOwnership();
        void setChessPiece(std::unique_ptr<ChessPiece>);

    private:
        Color color;
        std::unique_ptr<ChessPiece> chessPiece{nullptr};
    };
}

#endif