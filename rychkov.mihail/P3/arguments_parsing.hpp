#ifndef ARGUMENTS_PARSING_HPP
#define ARGUMENTS_PARSING_HPP

#include <iosfwd>

namespace rychkov
{
  int parseArguments(std::ostream& errStream, int argc, char** argv, int& testMode);
}

#endif
