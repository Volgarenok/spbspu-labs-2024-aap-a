#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.h"

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
  const char* st = argv[1];
  long int numer = 0;
  try
  {
    numer = komarova::notanum(st);
  }
  catch (const std::logic_error & e)
  {
    std::cout << e.what() << "\n";
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

  size_t m = 0, n = 0;
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

  size_t size_arr = m * n;
  int array_1[10000] = {};
  int * array = nullptr;
  int * array_2 = nullptr;

  if (numer == 1)
  {
    array = array_1;
  }
  if (numer == 2)
  {
    try
    {
      array_2 = new int[size_arr];
      array = array_2;
    }
    catch (const std::bad_alloc & e)
    {
      delete[] array_2;
      std::cerr << "We're do not have memory for you, sorry \n";
      return 1;
    }
  }
  if (!(komarova::input_m(input, array, size_arr)))
  {
    delete[] array_2;
    std::cerr << "Input fail \n";
    return 2;
  }
  if ((komarova::checktri(array, m) == true) && (m > 1))
  {
    output << "true";
  }
  else
  {
    output << "false";
  }
  delete[] array_2;
}
