#include "GameBoard.h"
#include "Tetromino.h"

GameBoard::GameBoard(int width, int height) : width(width), height(height) {
    board.resize(height, std::vector<int>(width, 0));
}

void GameBoard::clearBoard() {
    for (auto &row : board) {
        std::fill(row.begin(), row.end(), 0);
    }
}

void GameBoard::draw(QPainter &painter) {
    // ✅ Draw board background
    painter.fillRect(0, 0, width * 30, height * 30, Qt::white); // ✅ white background

    // Draw locked blocks
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (board[y][x] != 0) {
                painter.fillRect(x * 30, y * 30, 30, 30, Qt::red);
            }
        }
    }
}

bool GameBoard::placeTetromino(Tetromino *tetromino) {
    return true;
}

void GameBoard::lockTetromino(Tetromino* tetromino, int x, int y) {
    auto shape = tetromino->getShape();
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != 0) {
                int boardY = y + i;
                int boardX = x + j;
                if (boardY >= 0 && boardY < height && boardX >= 0 && boardX < width) {
                    board[boardY][boardX] = 1;
                }
            }
        }
    }
}

int GameBoard::clearFullLines() {
    int linesCleared = 0;
    for (int y = 0; y < height; ++y) {
        if (std::all_of(board[y].begin(), board[y].end(), [](int cell) { return cell != 0; })) {
            board.erase(board.begin() + y);
            board.insert(board.begin(), std::vector<int>(width, 0));
            linesCleared++;
        }
    }
    return linesCleared;
}

int GameBoard::getCell(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height)
        return 1; // treat out of bounds as occupied
    return board[y][x];
}
