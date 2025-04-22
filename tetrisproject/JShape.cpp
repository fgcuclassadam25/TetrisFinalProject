#include "JShape.h"
#include "RotationUtils.h"

JShape::JShape() {
    shape = {
        {0, 0, 1},
        {1, 1, 1}
    };
}

void JShape::rotate() {
    rotateClockwise(shape);
}

void JShape::draw(QPainter &painter, int x, int y) {
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != 0) {
                painter.fillRect((x + j) * 30, (y + i) * 30, 30, 30, Qt::blue);
            }
        }
    }
}

std::vector<std::vector<int>> JShape::getShape() const {
    return shape;
}
