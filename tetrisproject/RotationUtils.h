#ifndef ROTATIONUTILS_H
#define ROTATIONUTILS_H

#include <vector>

inline void rotateClockwise(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> rotated(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            rotated[j][rows - 1 - i] = matrix[i][j];

    matrix = rotated;
}

#endif // ROTATIONUTILS_H

