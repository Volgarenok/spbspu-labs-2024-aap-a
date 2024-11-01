#ifndef PARSE_ARGUMENTS_HPP
#define PARSE_ARGUMENTS_HPP

#include <ostream>

namespace kizhin {
  void parseArguments(std::ostream& errorStream, int argc, char* const* argv,
      int* programMode, char** inputFile, char** outputFile);
  int parseProgrammMode(const char* string);
}

#endif
