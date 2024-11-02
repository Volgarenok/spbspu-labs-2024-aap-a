#ifndef MATRIX_FUNCTIONS_HPP
#define MATRIX_FUNCTIONS_HPP

#include <iostream>

std::istream & matrixInput(std::istream & in, int * matrix, size_t nRows, size_t nColumns);
size_t getNumberOfRequiredColumns(const int * const matrix, size_t nRows, size_t nColumns);

#endif