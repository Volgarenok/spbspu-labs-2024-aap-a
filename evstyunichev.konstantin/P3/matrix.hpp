#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
namespace evstyunichev
{
    size_t cstring_len(char* s);
    std::istream & input(std::istream & fin, int* arr, size_t m, size_t n, size_t &read);
    bool isRowNsm(int* arr, size_t i, size_t n);
    size_t CntRowsNsm(int* arr, size_t m, size_t n);
    void ddel(int* arr, int num);
}
#endif
