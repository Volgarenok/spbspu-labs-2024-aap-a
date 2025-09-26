#include "delimeterIO.hpp"

std::istream& maslovskiy::operator>>(std::istream& in, DelimiterIO&& dest)
{
  std::istream::sentry s(in);
  if (!s)
  {
    return in;
  }
  char c = '0';
  in >> c;
  if (in && (c != dest.delim))
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}
