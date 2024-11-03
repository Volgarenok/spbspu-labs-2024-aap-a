#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <cstddef>

std::istream & inputMtx(std::istream & in, int * arr, size_t m, size_t n, size_t & read);
void outputMtx(std::ostream & out, int * arr, size_t m, size_t n);
size_t searchNumLogMin(int * arr, size_t general);
#endif
