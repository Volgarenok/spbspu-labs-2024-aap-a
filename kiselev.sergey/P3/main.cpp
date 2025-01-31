#include <cstring>
#include <fstream>
#include <iostream>
#include <new>
#include <stdexcept>
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
  else if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
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
  if (input.fail())
  {
    std::cerr << "Incorrect parameters\n";
    return 2;
  }
  int number_element = 0;
  int* dynMatrix = nullptr;
  constexpr size_t length = 100000;
  int fixedArray[length];
  try
  {
    dynMatrix = argv[1][0] == '1' ? nullptr : new int[rows * columns];
    int* matrix = argv[1][0] == '2' ? dynMatrix : fixedArray;
    kiselev::inputMatrix(input, matrix, rows, columns, count_read);
    if (count_read != rows * columns)
    {
      throw std::logic_error("Incorrected matrix");
    }
    number_element = kiselev::saddleElement(matrix, rows, columns);
    const char* outFile = argv[3];
    std::ofstream output(outFile);
    output << "The number of elements read: " << count_read << "\n";
    output << "Number of saddle elements: " << number_element << "\n";
    delete[] dynMatrix;
    return 0;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    return 2;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "Incorrect input matrix\n";
    delete[] dynMatrix;
    return 2;
  }
}
