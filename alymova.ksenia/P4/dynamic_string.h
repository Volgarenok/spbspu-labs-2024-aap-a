#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H
#include <cstddef>
namespace alymova
{
  char* create(size_t size);
  char* increase_string(char* str, char* size_new);
  char* upper_string(char* str);
}
#endif
