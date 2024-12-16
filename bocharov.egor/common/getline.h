#ifndef GETLINE_H
#define GETLINE_H
#include <iostream>
namespace bocharov
{
  char * extend_string(const char * string, std::size_t capacity, std::size_t current_lenght);
  char * getline(std::istream & in, char end_symbol);
}
#endif
