#include "Chess.h"

namespace chess
{
    Chess::Chess()
    {
        board.place({0, 4}, createChessPiece<King>(Color::black));
        board.place({7, 4}, createChessPiece<King>(Color::white));
    }

    void Chess::move(Position from, Position to)
    {
        auto chessPiece = board.getSquare(from).getChessPiece();
        if (!chessPiece || chessPiece->getColor() != currentPlayer->getColor())
            return;
        // TODO
        currentPlayer->stopTime(clock);
        nextPlayer();
    }

    void Chess::nextPlayer()
    {
        if (currentPlayer == &players.first)
            currentPlayer = &players.second;
        else
            currentPlayer = &players.first;
    }
}