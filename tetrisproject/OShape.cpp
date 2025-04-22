#include "OShape.h"

OShape::OShape() {
    shape = {
        {1, 1},
        {1, 1}
    };
}

void OShape::rotate() {
    // No rotation needed for square
}

void OShape::draw(QPainter &painter, int x, int y) {
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != 0) {
                painter.fillRect((x + j) * 30, (y + i) * 30, 30, 30, Qt::yellow);
            }
        }
    }
}

std::vector<std::vector<int>> OShape::getShape() const {
    return shape;
}
