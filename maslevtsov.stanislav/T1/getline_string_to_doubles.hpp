#ifndef GETLINE_STRING_TO_DOUBLES_HPP
#define GETLINE_STRING_TO_DOUBLES_HPP

#include <istream>

namespace maslevtsov
{
  double* getlineStringToDoubles(std::istream& in, std::size_t& read);
}

#endif
