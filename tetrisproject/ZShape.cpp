#include "ZShape.h"
#include "RotationUtils.h"

ZShape::ZShape() {
    shape = {
        {1, 1, 0},
        {0, 1, 1}
    };
}

void ZShape::rotate() {
    rotateClockwise(shape);
}

void ZShape::draw(QPainter &painter, int x, int y) {
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != 0) {
                painter.fillRect((x + j) * 30, (y + i) * 30, 30, 30, Qt::green);
            }
        }
    }
}

std::vector<std::vector<int>> ZShape::getShape() const {
    return shape;
}
