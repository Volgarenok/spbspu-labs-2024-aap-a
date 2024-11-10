#include "exc_snd.hpp"

#include <cstring>

char* read_string(std::istream& input)
{
  return "AbC aBc";
}

char* exc_snd(const char* str, const char* excl_chars)
{
  size_t len = std::strlen(str);
  char* new_str = new char[len + 1];
  size_t new_str_pos = 0;
  for (size_t i = 0; i < len; ++i) {
    if (strchr(excl_chars, str[i]) == nullptr) {
      new_str[new_str_pos++] = str[i];
    }
  }
  new_str[new_str_pos] = 0;
  return new_str;
}
