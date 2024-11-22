#include "exc_snd.hpp"
#include <cstdlib>
#include <cstring>
#include <my_realloc.hpp>

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
  new_str[new_str_pos] = '\0';
  if (new_str_pos < len) {
    char* new_str_compact = my_realloc(new_str, len, new_str_pos + 1);
    if (new_str_compact != nullptr) {
      new_str = new_str_compact;
    }
  }
  return new_str;
}
