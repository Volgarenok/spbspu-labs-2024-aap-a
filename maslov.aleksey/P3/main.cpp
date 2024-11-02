#include <iostream>
#include <fstream>
#include <cstdlib>
#include "arrays.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  char* endptr = nullptr;
  long taskNumber = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if(!(taskNumber == 1 || taskNumber == 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);

  size_t m = 0, n = 0;
  input >> m >> n;

  if (!input)
  {
    std::cerr << "Rows or columns not a number\n";
    return 2;
  }
  if (m == 0 || n == 0)
  {
    std::cerr << "Matrix cannot be created\n";
    return 2;
  }

  size_t read = 0;
  int ** t = nullptr;
  try
  {
    t = maslov::createMatrix(m,n);
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }

  maslov::inputMatrix(input, t, m, n, read);

  if (taskNumber == 1)
  {
    constexpr size_t max_size = 10000;
    int array[max_size] = {};
    int * staticArray = maslov::convert(t, m, n, array);
    maslov::destroyMatrix(t,m);
    for (size_t i = 0; i < n * m; i++)
    {
      std::cout << staticArray[i] << " ";
    }
    std::cout << "\n";
  }
  else
  {
    const size_t arraySize = m * n;
    int * array = new int[arraySize];
    int * dynamicArray = maslov::convert(t, m, n, array);
    for (size_t i = 0; i < arraySize; i++)
    {
      std::cout << dynamicArray[i] << " ";
    }
    std::cout << "\n";
  }
  // maslov::outputMatrix(output);
}
