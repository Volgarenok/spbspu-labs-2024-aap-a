#include "io_utils.hpp"

std::istream& kizhin::readMatrixDimensions(
    std::istream& in, size_t* rows, size_t* columns)
{
  in >> *rows >> *columns;
  return in;
}

std::istream& kizhin::readArrayValues(std::istream& in, int* array, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    in >> array[i];
  }
  return in;
}

std::ostream& kizhin::writeResultToFile(std::ostream& out, size_t result)
{
  out << result;
  return out;
}

