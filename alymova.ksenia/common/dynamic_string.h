#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H
#include <cstddef>
#include <istream>
namespace alymova
{
  char* copy_string(const char* str, size_t end, char* size_new);
  char* get_string(std::istream& in, size_t& capacity, size_t& size, int ratio, char delim);
}
#endif
