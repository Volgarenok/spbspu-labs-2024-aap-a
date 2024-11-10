#include <iostream>
#include "spiral_decrement.h"
namespace lungu {

void spiralDecrement(int** const matrix, const int rows, const int cols) {
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    int increment = 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            matrix[bottom][i] += increment++;
        }
        bottom--;
        for (int i = bottom; i >= top; --i) {
            matrix[i][right] += increment++;
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[top][i] += increment++;
            }
            top++;
        }
        if (left <= right) {
            for (int i = top; i <= bottom; ++i) {
                matrix[i][left] += increment++;
            }
            left++;
        }
    }
}

}

