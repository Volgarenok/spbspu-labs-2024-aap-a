#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H
#include <cstddef>
namespace alymova
{
<<<<<<< HEAD
  //char* create(size_t size);
  char* copy_string(char* str, char* size_new);
  char* upper_string(const char* str, char* str_res);
=======
  char* copy_string(const char* str, size_t end, char* size_new);
>>>>>>> alymova.ksenia/P4
  char* get_string(size_t& size, size_t& size_now, int ratio, char delim);
}
#endif
