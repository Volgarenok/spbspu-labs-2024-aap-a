#include "count_columns.h"
namespace lungu
{
    int countColumnsWithoutConsecutiveDuplicates(int** matrix, int rows, int cols)
    {
        int count = 0;

        for (int col = 0; col < cols; ++col) {
            bool hasConsecutive = false;
            for (int row = 1; row < rows; ++row) {
                if (matrix[row][col] == matrix[row - 1][col]) {
                    hasConsecutive = true;
                    break;
                }
            }
            if (!hasConsecutive) {
                count++;
            }
        }
        return count;
    }
}
