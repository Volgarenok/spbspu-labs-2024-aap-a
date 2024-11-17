#include <iostream>
#include <stdexcept>
#include "cnt_nzr_dig.hpp"

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "ERROR: Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "ERROR: Too many arguments\n";
    return 1;
  }
  if (!(argv[1][0] == '1' || argv[1][0] == '2') || argv[1][1] != '\0')
  {
    std::cerr << "ERROR: First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t num_rows = 0, num_columns = 0, num_diagonal = 0, read = 0;
  input >> num_rows >> num_columns;
  if (argv[1][0] == '1')
  {
    const int LEN = 10000;
    int matrix1[LEN] = {};
    try
    {
      num_diagonal = sveshnikov::process_matrix(input, matrix1, num_rows, num_columns, read);
    }
    catch (const std::istream::failure &e)
    {
      std::cerr << "ERROR: Can not read: " << e.what() << "\n";
      return 2;
    }
  }
  else if (argv[1][0] == '2')
  {
    size_t len = num_columns * num_rows;
    int *matrix2 = nullptr;
    try
    {
      matrix2 = new int[len];
      num_diagonal = sveshnikov::process_matrix(input, matrix2, num_rows, num_columns, read);
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "ERROR: Memory Allocation: " << e.what() << "\n";
      return 2;
    }
    catch (const std::istream::failure &e)
    {
      std::cerr << "ERROR: Can not read: " << e.what() << "\n";
      delete[] matrix2;
      return 2;
    }
    delete[] matrix2;
  }
  std::ofstream output(argv[3]);
  output << num_diagonal;
  output << "\n";
}

size_t sveshnikov::process_matrix(std::istream &in, int *matrix, size_t num_rows, size_t num_columns, size_t &read)
{
  if (!sveshnikov::read_matrix(in, matrix, num_rows, num_columns, read) || read != num_rows * num_columns)
  {
    std::cerr << "ERROR: It cannot be interpreted as a two-dimensional array\n";
    throw std::istream::failure("ERROR: can not read");
  }
  return sveshnikov::cnt_nzr_dig(matrix, num_rows, num_columns);
}
