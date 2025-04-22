#ifndef ZSHAPE_H
#define ZSHAPE_H

#include "Tetromino.h"

class ZShape : public Tetromino {
public:
    ZShape();
    void rotate() override;
    void draw(QPainter &painter, int x, int y) override;
    std::vector<std::vector<int>> getShape() const override;

private:
    std::vector<std::vector<int>> shape;
};

#endif // ZSHAPE_H
