#ifndef LSHAPE_H
#define LSHAPE_H

#include "Tetromino.h"

class LShape : public Tetromino {
public:
    LShape();
    void rotate() override;
    void draw(QPainter &painter, int x, int y) override;
    std::vector<std::vector<int>> getShape() const override;

private:
    std::vector<std::vector<int>> shape;
};

#endif // LSHAPE_H
