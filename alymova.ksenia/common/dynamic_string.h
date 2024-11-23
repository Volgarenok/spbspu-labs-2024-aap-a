#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H
#include <cstddef>
namespace alymova
{
  char* copy_string(const char* str, size_t end, char* size_new);
  char* get_string(size_t& size, size_t& size_now, int ratio, char delim);
}
#endif
