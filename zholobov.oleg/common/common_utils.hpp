#ifndef COMMON_UTILS_HPP
#define COMMON_UTILS_HPP

#include <cstddef>
#include <istream>

namespace zholobov {

  template < typename T >
  void read_array(T* data, size_t count, std::istream& input_stream)
  {
    for (size_t i = 0; i < count; ++i) {
      if (!(input_stream >> data[i])) {
        throw std::logic_error("Stream read error");
      }
    }
  }
}

#endif
