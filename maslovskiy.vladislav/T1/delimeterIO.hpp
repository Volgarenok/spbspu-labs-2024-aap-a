#ifndef DELIMETERIO_HPP
#define DELIMETERIO_HPP
#include <iomanip>

namespace maslovskiy
{
  struct DelimiterIO
  {
    char delim;
  };
  std::istream& operator>>(std::istream& in, DelimiterIO&& dest);
}

#endif
