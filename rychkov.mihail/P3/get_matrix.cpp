#include "get_matrix.hpp"

int rychkov::getMatrix(std::istream& inpStream, int* matrix, size_t height, size_t width)
{
  for (size_t i = 0; i < height * width; i++)
  {
    if (!(inpStream >> matrix[i]))
    {
      return i;
    }
  }
}
