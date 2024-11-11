#include "exc_snd.hpp"

#include <cstring>
#include <cstdlib>

char* read_string(std::istream& input)
{
  return "AbC aBc";
}

char* exc_snd(const char* str, const char* excl_chars)
{
  size_t len = std::strlen(str);
  char* new_str = (char*)std::malloc(len + 1);
  size_t new_str_pos = 0;
  for (size_t i = 0; i < len; ++i) {
    if (std::strchr(excl_chars, str[i]) == nullptr) {
      new_str[new_str_pos++] = str[i];
    }
  }
  new_str[new_str_pos] = 0;
  new_str = (char*)std::realloc(new_str, new_str_pos + 1);
  return new_str;
}
