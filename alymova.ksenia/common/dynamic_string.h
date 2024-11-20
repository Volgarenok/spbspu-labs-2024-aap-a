#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H
#include <cstddef>
namespace alymova
{
  char* create(size_t size);
  char* copy_string(char* str, char* size_new);
  char* upper_string(char* str);
  char* get_string(char* str, size_t& size, size_t& size_now, int ratio, char delim);
}
#endif
