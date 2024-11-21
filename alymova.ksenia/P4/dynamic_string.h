#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H
#include <cstddef>
namespace alymova
{
  char* copy_string(const char* str, char* size_new);
  char* upper_string(const char* str, char* str_res);
  char* get_string(size_t& size, size_t& size_now, int ratio, char delim);
}
#endif
