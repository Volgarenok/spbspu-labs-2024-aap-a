#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "input_matrix.h"
#include "output_matrix.h"

int main(int argc, char ** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  else if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  long int num = 0;
  const char *str = argv[1];
  char* endptr = nullptr;
  num = std::strtol(str, std::addressof(endptr), 10);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range" << "\n";
    return 1;
  }
  size_t strk = 0;
  size_t stl = 0;
  size_t size_matrix = 0;
  std::ifstream input(argv[2]);
  input >> strk >> stl;
  if (!input)
  {
    std::cerr << "Not a matrix" << "\n";
    return 2;
  }
  size_matrix = strk * stl;
  std::ofstream output(argv[3]);
  int static_matrix[10000];
  int *matrix = static_matrix;
  matrix = new int[size_matrix];
  if (!finaev::input_matrix(input, matrix, size_matrix))
  {
    if (num == 2)
    {
      delete[] matrix;
    }
    std::cerr << "Fail input" << "\n";
    return 2;
  }
  finaev::output_matrix(output, matrix, strk, stl);
  if (num == 2)
  {
    delete[] matrix;
  }
  return 0;
}
