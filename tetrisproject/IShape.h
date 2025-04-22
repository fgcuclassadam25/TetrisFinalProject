#ifndef ISHAPE_H
#define ISHAPE_H

#include "Tetromino.h"

class IShape : public Tetromino {
public:
    IShape();
    void rotate() override;
    void draw(QPainter &painter, int x, int y) override;
    std::vector<std::vector<int>> getShape() const override;

private:
    std::vector<std::vector<int>> shape;
};

#endif // ISHAPE_H

