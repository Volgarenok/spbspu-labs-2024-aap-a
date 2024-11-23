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
  if (!in)
  {
    std::cerr << "Cannot read size of matrix\n";
    return 2;
  }
  size_t matrixSize = rows * cols;
  int matrix[10000] = {0};
  int* dynamicMatrix = nullptr;
  try
  {
    if (num == 2)
    {
      dynamicMatrix = new int[matrixSize];
      inputMatrix(in, dynamicMatrix, matrixSize);
      if (!in)
      {
        throw std::logic_error("Not enough data to fill the matrix");
      }
      cntCol = countNoDuplicates(dynamicMatrix, rows, cols);
    }
    else
    {
      inputMatrix(in, matrix, matrixSize);
      if (!in)
      {
        throw std::logic_error("Not enough data to fill the matrix");
      }
      cntCol = countNoDuplicates(matrix, rows, cols);
    }
    std::ofstream output(argv[3]);
    if (!output)
    {
      throw std::logic_error("Cannot open output file");
    }
    output << cntCol << "\n";
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
