#include "LShape.h"
#include "RotationUtils.h"

LShape::LShape() {
    shape = {
        {1, 0, 0},
        {1, 1, 1}
    };
}

void LShape::rotate() {
    rotateClockwise(shape);
}

void LShape::draw(QPainter &painter, int x, int y) {
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != 0) {
                painter.fillRect((x + j) * 30, (y + i) * 30, 30, 30, Qt::darkYellow);
            }
        }
    }
}

std::vector<std::vector<int>> LShape::getShape() const {
    return shape;
}
