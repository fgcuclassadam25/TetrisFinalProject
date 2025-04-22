#ifndef TSHAPE_H
#define TSHAPE_H

#include "Tetromino.h"

class TShape : public Tetromino {
public:
    TShape();
    void rotate() override;
    void draw(QPainter &painter, int x, int y) override;
    std::vector<std::vector<int>> getShape() const override;

private:
    std::vector<std::vector<int>> shape;
};

#endif // TSHAPE_H
