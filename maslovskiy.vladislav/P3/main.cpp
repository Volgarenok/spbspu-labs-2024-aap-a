#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include "countInMtx.hpp"
#include "inputMatrix.hpp"

int main(int argc, char** argv)
{
  using namespace maslovskiy;
  long long num = 0;
  int cntCol = 0;
  try
  {
    if (argc != 4)
    {
      throw std::logic_error("Wrong number of parametres");
    }
    const char *str = argv[1];
    char *str_end = nullptr;
    num = std::strtoll(str, &str_end, 10);
    if (*str_end != '\0' || num == 0)
    {
      throw std::logic_error("Can not parse value");
    }
    if (num != 1 && num != 2)
    {
      throw std::logic_error("Incorrect parametr");
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
  if (!in)
  {
    std::cerr << "Can not read size of matrix" << '\n';
    return 2;
  }
  size_t matrixSize = cols * rows;
  int matrix[10000] = {0};
  int *dynamicMatrix = nullptr;
  try
  {
    if (num == 1)
    {
      inputMatrix(in, matrix, matrixSize);
      cntCol = countNoDuplicates(matrix, rows, cols);
    }
    if (num == 2)
    {
      dynamicMatrix = new int [matrixSize];
      for (size_t i = 0; i < matrixSize; ++i)
      {
        dynamicMatrix[i] = 0;
      }
      inputMatrix(in, dynamicMatrix, matrixSize);
      cntCol = countNoDuplicates(dynamicMatrix, rows, cols);
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Cannot allocate memory for matrix\n";
    return 2;
  }
  catch (const std::exception &e)
  {
    if (num == 2)
    {
      delete [] dynamicMatrix;
    }
    std::cerr << e.what() << "\n";
    return 2;
  }
std::ofstream output(argv[3]);
output << cntCol << "\n";
if (num == 2)
  {
    delete [] dynamicMatrix;
  }
}
