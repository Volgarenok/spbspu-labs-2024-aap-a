#include "checkFirst.h"
#include "inputMatrix.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "To many arguments\n";
    return 1;
  }
  else if (!kiselev::checkFirst(argv[1]))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  else if (argv[1][1] != '\0' || (argv[1][0] != '1' && argv[1][0] != '2'))
  {

    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  char* inFile = argv[2];
  std::ifstream input(inFile);
  if (!input.is_open())
  {
    std::cerr << "The file cannot be opened\n";
    return 1;
  }
  size_t m = 0, n = 0;
  input >> m >> n;
  if (argv[1][0] == '1')
  {
    int fixed_array[m * n];
    try
    {
      kiselev::inputMatrix(input, fixed_array, m, n);
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what();
      return 2;
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what();
      return 2;
    }
  }
  if (argv[1][0] == '2')
  {
    int* din_array = nullptr;
    try
    {
      din_array = new int[m * n];
      kiselev::inputMatrix(input, din_array, m, n);
    }
    catch (std::bad_alloc& e)
    {
      std::cerr << "Out of memory\n";
      delete[] din_array;
      return 2;
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what();
      delete[] din_array;
      return 2;
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what();
      delete[] din_array;
      return 2;
    }
  }
  char* outFile = argv[3];
  std::ofstream output(outFile);
}

