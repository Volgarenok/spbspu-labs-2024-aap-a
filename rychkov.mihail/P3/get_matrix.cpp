#include "get_matrix.hpp"

#include <iostream>

std::istream& rychkov::getMatrix(std::istream& inpStream, int* matrix,
    size_t height, size_t width, size_t& wereRead)
{
  for (size_t i = 0; i < height * width; i++)
  {
    if (!(inpStream >> matrix[i]))
    {
      wereRead = i;
      return inpStream;
    }
  }
  wereRead = height * width;
  return inpStream;
}
