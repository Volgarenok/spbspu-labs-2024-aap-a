#include "exc_snd.hpp"
#include <cstdlib>
#include <cstring>
#include <istream>

char* zholobov::read_string(std::istream& input)
{
  constexpr size_t buf_size = 16;
  char buf[buf_size];
  size_t buf_pos = 0;
  char* str = static_cast< char* >(std::malloc(1));
  size_t str_length = 0;
  char c = '\0';
  std::noskipws(input);
  while ((input >> c) && (c != '\n')) {
    buf[buf_pos++] = c;
    if (buf_pos == buf_size) {
      str = static_cast< char* >(std::realloc(str, str_length + buf_size));
      for (size_t i = 0; i < buf_size; ++i, ++str_length) {
        str[str_length] = buf[i];
      }
      buf_pos = 0;
    }
  }
  if (c == '\n') {
    str = static_cast< char* >(std::realloc(str, str_length + buf_pos + 1));
    for (size_t i = 0; i < buf_pos; ++i, ++str_length) {
      str[str_length] = buf[i];
    }
    str[str_length] = '\0';
  }
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
