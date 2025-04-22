#ifndef SSHAPE_H
#define SSHAPE_H

#include "Tetromino.h"

class SShape : public Tetromino {
public:
    SShape();
    void rotate() override;
    void draw(QPainter &painter, int x, int y) override;
    std::vector<std::vector<int>> getShape() const override;

private:
    std::vector<std::vector<int>> shape;
};

#endif // SSHAPE_H
