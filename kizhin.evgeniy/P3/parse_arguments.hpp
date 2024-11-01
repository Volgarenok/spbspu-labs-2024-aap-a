#ifndef PARSE_ARGUMENTS_HPP
#define PARSE_ARGUMENTS_HPP

#include "memory_modes.hpp"
#include <ostream>

namespace kizhin {
  void parseArguments(std::ostream& errorStream, int argc, char* const* argv,
      MemoryMode* programMode, char** inputFile, char** outputFile);
  MemoryMode parseProgrammMode(const char*);
}

#endif
