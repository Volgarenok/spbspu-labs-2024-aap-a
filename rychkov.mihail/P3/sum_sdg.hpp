#ifndef SUM_SDG_HPP
#define SUM_SDG_HPP

#include <cstddef>

namespace rychkov
{
  int getMaxSumSdg(const int* matrix, size_t height, size_t width);
  int getSumOfSdgWithCell(const int* matrix, size_t height, size_t width, size_t basisY, size_t basisX);
}

#endif
