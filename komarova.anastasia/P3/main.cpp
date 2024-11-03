
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "table.h"

int main(int argc, char ** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  char * st = argv[1];
  if (komarova::nechislo(st))
  {
    std::cout << "First parameter is not a number\n";
    return 1;
  }
  if ((atoi(st) > 2) || (atoi(st) < 1))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);

  if (!output)
  {
    return 2;
  }

  if (input.eof())
  {
    std::cerr << "Input fail \n";
    return 2;
  }

  int m = 0, n = 0;
  input >> m >> n;
  if (!input)
  {
    std::cerr << "Incorrect input\n";
    return 2;
  }
  if (m != n)
  {
    return 2;
  }
  const int size_arr = m * n;
  if (atoi(st) == 1)
  {
    int array_1[10000] = {};
    komarova::input_m(input, array_1, size_arr);
    komarova::checktri(output, array_1, m);
  }
  if (atoi(st) == 2)
  {
    int* array_2 = new int[size_arr];
    komarova::input_m(input, array_2, size_arr);
    komarova::checktri(output, array_2, m);
    delete[] array_2;
  }
}
//check
