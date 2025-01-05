#ifndef DYNAMIC_H
#define DYNAMIC_H
#include <istream>
#include <cstddef>
namespace komarova
{
  char * read(std::istream & input, size_t & size_str, size_t & size_str_now, char end_str);
}
#endif
