#ifndef TETROMINO_H
#define TETROMINO_H

#include <QPainter>
#include <vector>

class Tetromino {
public:
    virtual void rotate() = 0;
    virtual void draw(QPainter &painter, int x, int y) = 0;
    virtual std::vector<std::vector<int>> getShape() const = 0;
    virtual ~Tetromino() = default;
};

#endif // TETROMINO_H

