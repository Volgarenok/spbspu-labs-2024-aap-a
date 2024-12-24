#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

namespace beshimow {
    bool lwrTriMtx(const int* arr, size_t n);
    bool input(std::ifstream& inputFile, int* arr, size_t m);
}

#endif // MATRIX_HPP
