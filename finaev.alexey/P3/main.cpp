#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "input_matrix.h"
#include "quantity_loc_max.h"

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
  if (argv[1][0] == '\0')
  {
    std::cerr  << "First paremeter is empty" << "\n";
    return 1;
  }
  if (argv[1][1] != '\0' || (argv[1][0] != '1' && argv[1][0] != '2'))
  {
    std::cerr << "False first parameter" << "\n";
    return 1;
  }
  const char *str = argv[1];
  char* endptr = nullptr;
  long int num = 0;
  num = std::strtol(str, std::addressof(endptr), 10);
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
  std::ofstream output(argv[3]);
  if (strk <= 0 || stl <= 0)
  {
    output << strk << " " << stl << "\n";
    return 0;
  }
  size_matrix = strk * stl;
  int fixed_matrix[10000];
  int *dynamic_matrix = nullptr;
  int *matrix = nullptr;
  if (num == 2)
  {
    try
    {
      dynamic_matrix = new int[size_matrix];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Error memory alloc" << "\n";
      return 2;
    }
    matrix = dynamic_matrix;
  }
  else
  {
    matrix = fixed_matrix;
  }
  if (!finaev::input_matrix(input, matrix, size_matrix))
  {
    std::cerr << "Fail input" << "\n";
    delete[] dynamic_matrix;
    return 2;
  }
  output << finaev::quantity_loc_max(matrix, strk, stl) << "\n";
  delete[] dynamic_matrix;
  return 0;
}
