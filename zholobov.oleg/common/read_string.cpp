#include "read_string.hpp"
#include <istream>
#include <realloc_memory.hpp>

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
    if (!(input >> c) || (c == '\n')) {
      c = '\0';
    }
    buf[buf_pos++] = c;
    if ((buf_pos == buf_size) || (c == '\0')) {
      char* new_str = realloc_memory(str, str_pos, str_pos + buf_pos);
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
