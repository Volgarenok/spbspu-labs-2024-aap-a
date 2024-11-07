#ifndef LINEINPUT_HPP
#define LINEINPUT_HPP
#include <iostream>
#include <cstddef>
char* getLine(std::istream input, size_t size);
char* reallocate(char* line, size_t capacity);
#endif