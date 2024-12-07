#ifndef PARSE_ARGUMENTS_HPP
#define PARSE_ARGUMENTS_HPP

#include "memory_utils.hpp"

namespace kizhin {
  void checkArgumentsCount(int argc);
  MemoryMode parseMemoryMode(const char*);
}

#endif
