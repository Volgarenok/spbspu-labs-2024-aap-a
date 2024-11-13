#include "exc_snd.hpp"
#include <cstdlib>
#include <cstring>
#include <istream>

static char* my_realloc(char* p, size_t& current_size, size_t new_size)
{
  char* new_p = static_cast< char* >(std::malloc(new_size));
  if (new_p == nullptr) {
    return nullptr;
  }
  size_t min_size = (current_size > new_size) ? new_size : current_size;
  for (size_t i = 0; i < min_size; ++i) {
    new_p[i] = p[i];
  }
  free(p);
  current_size = new_size;
  return new_p;
}

char* zholobov::read_string(std::istream& input)
{
  constexpr size_t buf_size = 3;
  char buf[buf_size];
  size_t buf_pos = 0;
  char* str = static_cast< char* >(std::malloc(1));
  if (str == nullptr) {
    return nullptr;
  }
  size_t str_size = 1;
  size_t str_pos = 0;
  char c = '\0';
  std::noskipws(input);
  while ((input >> c) && (c != '\n')) {
    buf[buf_pos++] = c;
    if (buf_pos == buf_size) {
      char* new_str = my_realloc(str, str_size, str_pos + buf_size);
      if (new_str == nullptr) {
        free(str);
        return nullptr;
      }
      str = new_str;
      for (size_t i = 0; i < buf_size; ++i, ++str_pos) {
        str[str_pos] = buf[i];
      }
      buf_pos = 0;
    }
  }
  if (c == '\n') {
    char* new_str = my_realloc(str, str_size, str_pos + buf_size);
    if (new_str == nullptr) {
      free(str);
      return nullptr;
    }
    str = new_str;
    for (size_t i = 0; i < buf_pos; ++i, ++str_pos) {
      str[str_pos] = buf[i];
    }
    str[str_pos] = '\0';
  } else {
    free(str);
    str = nullptr;
  }
  return str;
}

char* zholobov::exc_snd(const char* str, const char* excl_chars)
{
  if (str == nullptr) {
    return nullptr;
  }
  size_t len = std::strlen(str);
  char* new_str = static_cast< char* >(std::malloc(len + 1));
  if (new_str == nullptr) {
    return nullptr;
  }
  size_t new_str_pos = 0;
  for (size_t i = 0; i < len; ++i) {
    if (std::strchr(excl_chars, str[i]) == nullptr) {
      new_str[new_str_pos++] = str[i];
    }
  }
  new_str[new_str_pos] = 0;
  if (new_str_pos < len) {
    char* new_str_compact = my_realloc(new_str, len, new_str_pos + 1);
    if (new_str_compact != nullptr) {
      new_str = new_str_compact;
    }
  }
  return new_str;
}
