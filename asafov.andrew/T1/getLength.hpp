#ifndef GET_LENGTH_HPP
#define GET_LENGTH_HPP
#include <algorithm>
namespace asafov
{
  template<typename T>
  double getLength(std::initializer_list<T> initlist)
  {
    return std::max(initlist) - std::min(initlist);
  }
}
#endif
