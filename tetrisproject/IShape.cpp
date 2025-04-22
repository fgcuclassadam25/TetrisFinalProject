#include "IShape.h"
#include "RotationUtils.h"

IShape::IShape() {
    shape = {{1, 1, 1, 1}};
}

void IShape::rotate() {
    rotateClockwise(shape);
}

void IShape::draw(QPainter &painter, int x, int y) {
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != 0) {
                painter.fillRect((x + j) * 30, (y + i) * 30, 30, 30, Qt::cyan);
            }
        }
    }
}

std::vector<std::vector<int>> IShape::getShape() const {
    return shape;
}
