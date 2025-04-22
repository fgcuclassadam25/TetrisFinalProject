#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "IShape.h"
#include "JShape.h"
#include "LShape.h"
#include "OShape.h"
#include "SShape.h"
#include "TShape.h"
#include "ZShape.h"
#include <cstdlib>

class ShapeFactory {
public:
    static Tetromino* createRandomShape() {
        int id = rand() % 7;
        switch (id) {
        case 0: return new IShape();
        case 1: return new JShape();
        case 2: return new LShape();
        case 3: return new OShape();
        case 4: return new SShape();
        case 5: return new TShape();
        case 6: return new ZShape();
        default: return new IShape();
        }
    }
};

#endif // SHAPEFACTORY_H
