#ifndef EXC_SND_HPP
#define EXC_SND_HPP

#include <istream>

namespace zholobov{
  char* read_string(std::istream& input);
  char* exc_snd(const char* str, const char* excl_chars);
}

#endif
