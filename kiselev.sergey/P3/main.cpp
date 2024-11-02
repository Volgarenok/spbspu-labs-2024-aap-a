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
  size_t rows = 0, columns = 0;
  input >> rows >> columns;
  if (!(input >> rows >> columns))
  {
    std::cerr << "Incorrect parameters\n";
    return 2;
  }
  int number_element = 0;
  if (argv[1][0] == '1')
  {
    constexpr size_t length = 10000;
    int fixed_array[length];
    kiselev::inputMatrix(input, fixed_array, rows, columns, count_read);
    if (count_read != rows * columns)
    {
      std::cerr << "There are not enough elements for the array\n";
      return 2;
    }
    number_element = kiselev::saddleElement(fixed_array, rows, columns);
  }
  if (argv[1][0] == '2')
  {
    int* dynArray = nullptr;
    try
    {
      dynArray = new int[rows * columns];
      kiselev::inputMatrix(input, dynArray, rows, columns, count_read);
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Out of memory\n";
      delete[] dynArray;
      return 2;
    }
    if (count_read != rows * columns)
    {
      std::cerr << "There are not enough elements for the array\n";
      delete[] dynArray;
      return 2;
    }
    if (!kiselev::inputMatrix(input, dynArray, rows, columns, count_read).good())
    {
      std::cerr << "Incorrect matrix\n";
      delete[] dynArray;
      return 2;
    }
    number_element = kiselev::saddleElement(dynArray, rows, columns);
    delete[] dynArray;
  }
  char* outFile = argv[3];
  std::ofstream output(outFile);
  output << "The number of elements read: " << count_read << "\n";
  output << "Number of saddle elements: " << number_element << "\n";
  return 0;
}

