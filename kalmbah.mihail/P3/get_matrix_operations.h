#ifndef GET_MATRIX_OPERATIONS_H
#define GET_MATRIX_OPERATIONS_H

#include <vector>
#include <string>

namespace kalmbah {

bool isNumber(const std::string& str);
std::vector<std::vector<int>> createSymmetricMatrices(const std::vector<std::vector<int>>& matrix);
std::vector<std::vector<int>> createSymmetricMatrices(const int matrix[100][100], int rows, int cols);

}

#endif
