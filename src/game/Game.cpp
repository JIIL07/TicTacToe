#include "Game.h"
#include <iostream>

Game::Game() : player1('X'), player2('O'), currentPlayer(&player1) {}

void Game::play() {
    while (!board.checkWin() && !board.isFull()) {
        board.display();
        displayCurrentPlayer();
        std::cout << "Enter row and column (1-3): ";
        int row, col;
        std::cin >> row >> col;
        row--; col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board.makeMove(row, col, currentPlayer->getSymbol())) {
            if (board.checkWin()) {
                std::cout << "Player " << currentPlayer->getSymbol() << " wins!\n";
                return;
            }
            switchPlayer();
        }
        else {
            std::cout << (row < 0 || row >= 3 || col < 0 || col >= 3 ? "Invalid input, please enter numbers from 1 to 3.\n" :
                "That space is already occupied, try again.\n");
        }
    }
    std::cout << "Game over, it's a draw!\n";
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void Game::displayCurrentPlayer() const {
    std::cout << "Current player: " << currentPlayer->getSymbol() << std::endl;
}
