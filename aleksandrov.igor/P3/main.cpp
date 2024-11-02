#include <iostream>
#include <fstream>
#include "periphery.h"

int main(int argc, char** argv)
{
  (void)argc;
  std::ifstream input(argv[2]);
  int m = 0, n = 0;
  input >> m >> n;
  const int size = m * n;
  std::ofstream output(argv[3]);
  if (argv[1][0] == '1')
  {
    constexpr int arraySize = 10000;
    int array[arraySize] = {};
    input >> array[0];
    for (int i = 1; i < size; ++i)
    {
      input >> array[i];
    }
    periphery(output, array, m, n);
  }
  else if (argv[1][0] == '2')
  {
    int *array = nullptr;
    array = new int[size];
    input >> array[0];
    for (int i = 1; i < size; ++i)
    {
      input >> array[i];
    }
    periphery(output, array, m, n);
    delete[] array;
  }
  else
  {
    std::cerr << "Wrong first parameter!\n";
    return 1;
  }
}

