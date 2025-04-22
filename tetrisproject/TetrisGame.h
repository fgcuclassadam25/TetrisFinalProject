#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include "GameBoard.h"
#include "Tetromino.h"

class TetrisGame : public QWidget {
    Q_OBJECT

public:
    TetrisGame(QWidget *parent = nullptr);
    ~TetrisGame();

signals:
    void gameOver(); // ✅ emits when player tops out

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateGame();

private:
    GameBoard *board;
    QTimer *timer;
    Tetromino *currentPiece;
    int currentX, currentY;
    int score;
    int speed;

    void startGame();
    void spawnNewPiece();
    bool canMoveDown();
    bool isInsideBounds(int x, int y, const std::vector<std::vector<int>>& shape);
    void drawScore(QPainter &painter);
};

#endif // TETRISGAME_H
