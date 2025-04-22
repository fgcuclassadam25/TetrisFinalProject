#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <QPainter>

class Tetromino;

class GameBoard {
public:
    GameBoard(int width, int height);
    void clearBoard();
    void draw(QPainter &painter);
    bool placeTetromino(Tetromino *tetromino); // placeholder
    void lockTetromino(Tetromino* tetromino, int x, int y);
    int clearFullLines();
    int getCell(int x, int y) const; // ✅ new

    int getHeight() const { return height; }
    int getWidth() const { return width; }

private:
    int width;
    int height;
    std::vector<std::vector<int>> board;
};

#endif // GAMEBOARD_H
