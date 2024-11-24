#include "exc_snd.hpp"
#include <cstdlib>
#include <cstring>
#include <istream>

static char* my_realloc(char* p, size_t current_size, size_t new_size)
{
  char* new_p = static_cast< char* >(std::malloc(new_size));
  if (new_p == nullptr) {
    return nullptr;
  }
  if (p == nullptr) {
    return new_p;
  }
  size_t min_size = (current_size > new_size) ? new_size : current_size;
  for (size_t i = 0; i < min_size; ++i) {
    new_p[i] = p[i];
  }
  std::free(p);
  return new_p;
}

char* zholobov::read_string(std::istream& input)
{
  constexpr size_t buf_size = 32;
  char buf[buf_size];
  size_t buf_pos = 0;
  char* str = nullptr;
  size_t str_pos = 0;
  char c = '\0';
  std::noskipws(input);
  do {
    if (!(input >> c)) {
      std::free(str);
      return nullptr;
    }
    if (c == '\n') {
      c = '\0';
    }
    buf[buf_pos++] = c;
    if ((buf_pos == buf_size) || (c == '\0')) {
      char* new_str = my_realloc(str, str_pos, str_pos + buf_pos);
      if (new_str == nullptr) {
        std::free(str);
        return nullptr;
      }
      str = new_str;
      for (size_t i = 0; i < buf_pos; ++i, ++str_pos) {
        str[str_pos] = buf[i];
      }
      buf_pos = 0;
    }
  } while (c != '\0');
  return str;
}

char* zholobov::exc_snd(char* dst, const char* src, const char* excl_chars)
{
  if (src == nullptr || dst == nullptr) {
    return nullptr;
  }
  size_t src_pos = 0;
  size_t dst_pos = 0;
  while (src[src_pos] != '\0') {
    bool found = false;
    const char* p = excl_chars;
    do {
      if (*p == src[src_pos]) {
        found = true;
        break;
      }
    } while (*p++);
    if (!found) {
      dst[dst_pos++] = src[src_pos];
    }
    ++src_pos;
  }
  dst[dst_pos] = '\0';
  return dst;
}
