#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include "checkFirst.h"
#include "inputMatrix.h"
#include "saddleElement.h"
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
  size_t count_read = 0;
  std::ifstream input(inFile);
  if (!input.is_open())
  {
    std::cerr << "The file cannot be opened\n";
    return 1;
  }
  size_t m = 0, n = 0;
  input >> m >> n;
  int number_element = 0;
  if (argv[1][0] == '1')
  {
    int fixed_array[10000] = {};
    kiselev::inputMatrix(input, fixed_array, m, n, count_read);
    if (count_read != m * n)
    {
      std::cerr << "There are not enough elements for the array\n";
      return 2;
    }
    number_element = kiselev::saddleElement(fixed_array, m, n);
  }
  if (argv[1][0] == '2')
  {
    int* din_array = nullptr;
    try
    {
      din_array = new int[m * n];
      kiselev::inputMatrix(input, din_array, m, n, count_read);
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Out of memory\n";
      delete[] din_array;
      return 2;
    }
    if (!kiselev::inputMatrix(input, din_array, m, n, count_read))
    {
      std::cerr << "Incorrect matrix\n";
      delete[] din_array;
      return 2;
    }
    if (count_read != m * n)
    {
      std::cerr << "There are not enough elements for the array\n";
      delete[] din_array;
      return 2;
    }
    number_element = kiselev::saddleElement(din_array, m, n);
    delete[] din_array;
  }
  char* outFile = argv[3];
  std::ofstream output(outFile);
  output << "The number of elements read: " << count_read << "\n";
  output << "Number of saddle elements: " << number_element << "\n";
  return 0;
}

