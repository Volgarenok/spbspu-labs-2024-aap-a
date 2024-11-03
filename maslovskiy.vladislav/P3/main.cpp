#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

void inputMatrix(std::istream &in, int *matrix, size_t matrixSize)
{
  for (size_t i = 0; i < matrixSize; ++i)
  {
    in >> matrix[i];
  }
  if (!in)
  {
    throw std::logic_error("Incorrect matrix");
  }
}
void outMatrix(int *matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for(size_t j = 0; j < cols; ++j)
    {
      std::cout << matrix[i * cols + j] << ' ';
    }
    std::cout << '\n';
  }
}
int countNoDuplicates(int *matrix, size_t rows, size_t cols)
{
  int count = 0;
  for (size_t j = 0; j < cols; ++j)
  {
    bool hasDupl = false;
    for (size_t i = 1; i < rows; ++i)
    {
      if (matrix[i * cols + j] == matrix[(i - 1) * cols + j])
      {
        hasDupl = true;
        break;
      }
    }
    if (!hasDupl)
    {
      ++count;
    }
  }
  return count;
}

int main(int argc, char** argv)
{
  long long num = 0;
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
  try
  {
    if (num == 1)
    {
      inputMatrix(in, matrix, matrixSize);
      outMatrix(matrix, rows, cols);
      countNoDuplicates(matrix, rows, cols);
    }
    if (num == 2)
    {
      int *dynamicMatrix = new int[matrixSize];
      inputMatrix(in, dynamicMatrix, matrixSize);
      countNoDuplicates(matrix, rows, cols);
    }
  }
  catch (std::logic_error &e)
  {
    std::cerr << e.what() << '\n';
    return 3;
  }
int cntCol = countNoDuplicates(matrix, rows, cols);
std::ofstream output(argv[3]);
output << cntCol << "\n";
}
