#include "iomatrix.hpp"
#include <stdexcept>

void shabalin::inputMatrix(std::istream &input, int *matrix, size_t countOfElements)
{
  for (size_t i = 0; i < countOfElements; ++i)
  {
    if (!(input >> matrix[i]))
    {
      throw std::logic_error("Can't input the matrix");
    }
  }
}

void shabalin::outputMatrix(std::ostream &output, const int *matrix, size_t rows, size_t cols)
{
  if ((!rows) && (!cols))
  {
    throw std::invalid_argument("Such matrix can not exist");
  }
  for (size_t i = 0; i < rows * cols - 1; i++)
  {
    output << matrix[i] << ' ';
  }
  output << matrix[rows * cols - 1];
}
