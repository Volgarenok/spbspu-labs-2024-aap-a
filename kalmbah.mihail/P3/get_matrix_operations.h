#ifndef GET_MATRIX_OPERATIONS_H
#define GET_MATRIX_OPERATIONS_H

#include <string>

namespace kalmbah {

void createSymmetricMatrices(const int matrix[100][100], int result[200][200], int rows, int cols);
void createSymmetricMatrices(const int * matrix, int * result, int rows, int cols);
void printMatrix(const int matrix[200][200], int rows, int cols, std::ofstream& outputFile);
void printMatrix(const int * matrix, int rows, int cols, std::ofstream& outputFile);

}

#endif
