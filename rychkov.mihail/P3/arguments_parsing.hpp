#ifndef ARGUMENTS_PARSING_HPP
#define ARGUMENTS_PARSING_HPP

#include <iosfwd>

namespace rychkov
{
  int parseArguments(std::ostream& errStream, int argc, const char*const* argv, int& testMode);
}

#endif
