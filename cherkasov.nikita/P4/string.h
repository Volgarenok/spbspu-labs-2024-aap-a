#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <istream>
namespace cherkasov
{
  char * getString(const char * input, std::size_t size) noexcept;
  char * inpputLine(std::istream & in);
  char * allocMemor(size_t container);
  char * leghtArray(char * oldArray, size_t newContainer);
}
#endif
