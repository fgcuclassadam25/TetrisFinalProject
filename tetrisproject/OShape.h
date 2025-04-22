#ifndef OSHAPE_H
#define OSHAPE_H

#include "Tetromino.h"

class OShape : public Tetromino {
public:
    OShape();
    void rotate() override;
    void draw(QPainter &painter, int x, int y) override;
    std::vector<std::vector<int>> getShape() const override;

private:
    std::vector<std::vector<int>> shape;
};

#endif // OSHAPE_H
