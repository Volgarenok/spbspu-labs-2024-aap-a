#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "input_matrix.hpp"


int main(int argc, char ** argv)
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not suitable" << "\n";
    return 1;
  }
  
  const int num = std::atoi(argv[1]);
  size_t m = 0, n = 0;
  size_t read = 0;
  std::ifstream input(argv[2]);
  input >> m >> n;
  if (!input)
  {
    std::cerr << "Input is incorrect" << "\n";
    return 2;
  }
  if (num == 1)
  {
    int matrix[10000] = {};
  }
  if (num == 2)
  {
    try
    {
      int * matrix = new int[m * n];
    }
    catch (const std::bad_alloc & e)
    {
      delete[] matrix;
      std::cerr << "Out of memory" << "\n";
      return 2;
    }
  }
  
  
  //...
  std::ofstream output(argv[3]);
}
