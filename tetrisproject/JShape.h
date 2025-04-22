#ifndef JSHAPE_H
#define JSHAPE_H

#include "Tetromino.h"

class JShape : public Tetromino {
public:
    JShape();
    void rotate() override;
    void draw(QPainter &painter, int x, int y) override;
    std::vector<std::vector<int>> getShape() const override;

private:
    std::vector<std::vector<int>> shape;
};

#endif // JSHAPE_H
