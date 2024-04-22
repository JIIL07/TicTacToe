#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    void display() const;
    bool makeMove(int row, int col, char player);
    bool checkWin() const;
    bool isFull() const;
private:
    char board[3][3];
};

#endif
#pragma once
