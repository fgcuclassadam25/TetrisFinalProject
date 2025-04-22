#include "TetrisGame.h"
#include "ShapeFactory.h"
#include <QPainter>
#include <cstdlib>
#include <ctime>

TetrisGame::TetrisGame(QWidget *parent) : QWidget(parent), score(0), speed(500) {
    resize(300, 600);
    setStyleSheet("background-color: black;");
    board = new GameBoard(10, 20);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TetrisGame::updateGame);
    srand(static_cast<unsigned>(time(nullptr)));
    startGame();
}

TetrisGame::~TetrisGame() {
    delete board;
    delete currentPiece;
}

void TetrisGame::startGame() {
    board->clearBoard();
    spawnNewPiece();
    timer->start(speed);
}

void TetrisGame::spawnNewPiece() {
    currentPiece = ShapeFactory::createRandomShape();
    currentX = 3;
    currentY = 0;
}

bool TetrisGame::canMoveDown() {
    auto shape = currentPiece->getShape();
    int h = shape.size();
    int w = shape[0].size();

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (shape[i][j]) {
                int newX = currentX + j;
                int newY = currentY + i + 1;

                if (newY >= board->getHeight() || board->getCell(newX, newY) != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool TetrisGame::isInsideBounds(int x, int y, const std::vector<std::vector<int>>& shape) {
    int shapeHeight = shape.size();
    int shapeWidth = shape[0].size();

    for (int i = 0; i < shapeHeight; ++i) {
        for (int j = 0; j < shapeWidth; ++j) {
            if (shape[i][j] != 0) {
                int newX = x + j;
                int newY = y + i;
                if (newX < 0 || newX >= board->getWidth() || newY >= board->getHeight()) {
                    return false;
                }
                if (board->getCell(newX, newY) != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void TetrisGame::updateGame() {
    if (canMoveDown()) {
        currentY++;
    } else {
        board->lockTetromino(currentPiece, currentX, currentY);
        delete currentPiece;

        int lines = board->clearFullLines();
        if (lines > 0) {
            score += lines * 100;
            speed = std::max(100, speed - 20);
            timer->start(speed);
        }

        spawnNewPiece();

        if (!canMoveDown()) {
            timer->stop();
            emit gameOver(); // ✅ trigger MainWindow screen change
        }
    }

    update();
}

void TetrisGame::keyPressEvent(QKeyEvent *event) {
    auto shape = currentPiece->getShape();
    switch (event->key()) {
    case Qt::Key_Left:
        if (isInsideBounds(currentX - 1, currentY, shape)) currentX--;
        break;
    case Qt::Key_Right:
        if (isInsideBounds(currentX + 1, currentY, shape)) currentX++;
        break;
    case Qt::Key_Up: {
        currentPiece->rotate();
        auto rotated = currentPiece->getShape();

        if (isInsideBounds(currentX, currentY, rotated)) break;

        if (isInsideBounds(currentX - 1, currentY, rotated)) {
            currentX -= 1; break;
        }
        if (isInsideBounds(currentX + 1, currentY, rotated)) {
            currentX += 1; break;
        }

        // Undo rotation
        currentPiece->rotate(); currentPiece->rotate(); currentPiece->rotate();
        break;
    }
    case Qt::Key_Down:
        if (canMoveDown()) currentY++;
        break;
    }
    update();
}

void TetrisGame::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    board->draw(painter);
    if (currentPiece)
        currentPiece->draw(painter, currentX, currentY);

    drawScore(painter);
}

void TetrisGame::drawScore(QPainter &painter) {
    painter.setPen(Qt::red);
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(10, 20, QString("Score: %1").arg(score));
}
