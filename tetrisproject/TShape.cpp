#include "TShape.h"
#include "RotationUtils.h"

TShape::TShape() {
    shape = {
        {0, 1, 0},
        {1, 1, 1}
    };
}

void TShape::rotate() {
    rotateClockwise(shape);
}

void TShape::draw(QPainter &painter, int x, int y) {
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != 0) {
                painter.fillRect((x + j) * 30, (y + i) * 30, 30, 30, Qt::gray);
            }
        }
    }
}

std::vector<std::vector<int>> TShape::getShape() const {
    return shape;
}
