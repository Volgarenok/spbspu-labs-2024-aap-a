#ifndef EXC_SND_HPP
#define EXC_SND_HPP

#include <istream>

namespace zholobov {
  char* read_string(std::istream& input);
  char* exc_snd(char* dst, const char* src, const char* excl_chars);
}

#endif
