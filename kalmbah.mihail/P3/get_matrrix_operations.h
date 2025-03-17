#ifndef GET_MATRRIX_OPERATIONS_H
#define GET_MATRRIX_OPERATIONS_H

#include <string>

namespace kalmbah {

bool isNumber(const std::string& str);
void createSymmetricMatrices(const int matrix[100][100], int result[200][200], int rows, int cols);
void createSymmetricMatrices(const int* matrix, int* result, int rows, int cols);

}

#endif
