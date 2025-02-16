#include "getline_string_to_doubles.hpp"
#include <string>

namespace
{
  double* expandDoubleArray(const double* data, std::size_t capacity)
  {
    double* newData = new double[capacity];
    for (std::size_t i = 0; i < capacity - 2; ++i)
    {
      newData[i] = data[i];
    }
    return newData;
  }
}

double* maslevtsov::getlineStringToDoubles(std::istream& in, std::size_t& read)
{
  std::size_t capacity = 2, iDoubleArray = 0;
  double* doubleArray = new double[capacity];
  std::string subStr = "";
  char symbol = '\0';

  std::noskipws(in);
  in >> symbol;
  while ((in >> symbol) && (symbol != '\n'))
  {
    if (iDoubleArray == capacity)
    {
      double* expandedDoubleArray = nullptr;
      try
      {
        expandedDoubleArray = expandDoubleArray(doubleArray, capacity += 2);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] doubleArray;
        throw;
      }
      delete[] doubleArray;
      doubleArray = expandedDoubleArray;
    }
    if (symbol == ' ')
    {
      doubleArray[iDoubleArray++] = std::stod(subStr);
      subStr = "";
      continue;
    }
    subStr += symbol;
  }
  doubleArray[iDoubleArray] = std::stod(subStr);
  std::skipws(in);
  read = iDoubleArray + 1;

  return doubleArray;
}
