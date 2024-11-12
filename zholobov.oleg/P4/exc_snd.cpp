#include "exc_snd.hpp"

#include <cstring>
#include <cstdlib>
#include <istream>

char* zholobov::read_string(std::istream& input)
{
  constexpr size_t buf_size = 101;
  char buf[buf_size];
  char* str = (char*)std::malloc(1);
  *str = 0;
  size_t str_length = 0;
  do {
    input.clear();
    input.getline(buf, buf_size);
    size_t count = (size_t)input.gcount();
    str_length += count;
    str = (char*)std::realloc(str, str_length);
    std::strcat(str, buf);
  } while(!input);
  return str;
}

char* zholobov::exc_snd(const char* str, const char* excl_chars)
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
