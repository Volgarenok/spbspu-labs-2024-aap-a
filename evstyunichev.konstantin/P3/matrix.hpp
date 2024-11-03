#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
size_t cstring_len(char* s);
std::istream & input(std::istream & in, int* arr, size_t m, size_t n, size_t &read);
bool isRowNsm(int* arr, size_t i, size_t n);
size_t CntRowsNsm(int* arr, size_t m, size_t n);
#endif