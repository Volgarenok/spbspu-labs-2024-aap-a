#ifndef LINEINPUT_HPP
#define LINEINPUT_HPP
#include <iostream>
#include <cstddef>
char* getLine(size_t size);
char* reallocate(char* line, size_t& capacity);
char* reallocate(char* line, size_t& capacity, size_t addSize);
#endif