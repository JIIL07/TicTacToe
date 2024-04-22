#include "Board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void Board::display() const {
    const std::string indent = "   ";
    std::cout << "\n" << indent;

    for (int i = 0; i < 3; i++) {
        if (i > 0) {
            std::cout << indent << "---+---+---\n" << indent;
        }
        for (int j = 0; j < 3; j++) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

bool Board::makeMove(int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool Board::checkWin() const {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if ((board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool Board::isFull() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
