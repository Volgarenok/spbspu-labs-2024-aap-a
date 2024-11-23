#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include "countInMtx.hpp"
#include "inputMatrix.hpp"
#include "hasDuplicatesInColumn.hpp"
int main(int argc, char** argv)
{
  using namespace maslovskiy;
  long long num = 0;
  int cntCol = 0;
  try
  {
    if (argc != 4)
    {
      throw std::logic_error("Wrong number of parameters");
    }
    const char *str = argv[1];
    char *str_end = nullptr;
    num = std::strtoll(str, std::addressof(str_end), 10);
    if (*str_end != '\0' || num == 0)
    {
      throw std::logic_error("Cannot parse value");
    }
    if (num != 1 && num != 2)
    {
      throw std::logic_error("Incorrect parameter");
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream in(argv[2]);
  in >> rows >> cols;
  size_t matrixSize = cols * rows; 
  int matrix[10000] = {0}; 
  int *matrixPointer = nullptr; 
  try 
  { 
    if (num == 1) 
    {
      matrixPointer = matrix; 
    } 
    if (num == 2) 
    { 
      matrixPointer = new int [matrixSize]; 
    } 
    inputMatrix(in, matrixPointer , matrixSize); 
    if (!in) 
    { 
      delete[] matrixPointer; 
      std::cerr << "Not enough data to fill the matrix\n"; 
      return 2; 
    } 
    cntCol = countNoDuplicates(matrixPointer, rows, cols);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Cannot allocate memory for matrix\n";
    delete[] dynamicMatrix;
    return 2;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << "\n";
    delete[] dynamicMatrix;
    return 2;
  }
  delete[] dynamicMatrix;
  return 0;
}
