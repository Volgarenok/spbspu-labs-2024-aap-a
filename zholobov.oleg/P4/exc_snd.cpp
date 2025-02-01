#include "exc_snd.hpp"
#include <cstdlib>
#include <cstring>

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
