#include "Chess.h"

#include "King.h"

namespace chess
{
    Chess::Chess()
    {
        board.place({0, 4}, createChessPiece<King>(Color::black));
        board.place({7, 4}, createChessPiece<King>(Color::white));
    }

    void Chess::move(Position from, Position to)
    {
        if (!currentPlayer->isOwnPiece(board, from))
            return;
        // TODO
        currentPlayer->stopTime(clock);
        nextPlayer();
        updateObservers();
    }

    void Chess::nextPlayer()
    {
        if (currentPlayer == &players.first)
            currentPlayer = &players.second;
        else
            currentPlayer = &players.first;
    }
}