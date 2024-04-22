#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
public:
    Game();
    void play();
private:
    Board board;
    Player player1, player2;
    Player* currentPlayer;
    void switchPlayer();
    void displayCurrentPlayer() const;
};

#endif