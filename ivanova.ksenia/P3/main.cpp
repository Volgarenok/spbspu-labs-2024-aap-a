#include <iostream>
#include <fstream>
#include "matrix.h"

int main(int argc, char ** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments!" << '\n';
    return 1;
  }
  else if (argc < 4)
  {
    std::cerr << "Not enough arguments!" << '\n';
    return 1;
  }
  else if (!std::isdigit(argv[1][0]) || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not a number!" << '\n';
    return 1;
  }

  if (argv[1][0] != '1' && argv[1][0] != '2')
  {
    std::cerr << "First parameter is must be 1 or 2!" << '\n';
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!input)
  {
    std::cerr << "File is empty!" << "\n";
    return 2;
  }
  if (m * n == 0)
  {
    output << "0" << '\n';
    return 0;
  }

  int fixArr[10000] = {0};
  int * matrix = nullptr;
  int * dynamArr = nullptr;
  size_t read = 0;

  if (argv[1][0] == '1')
  {
    matrix = fixArr;
  }
  else if (argv[1][0] == '2')
  {
    try
    {
      dynamArr = new int[m * n];
      matrix = dynamArr;
    }
    catch (const std::bad_alloc & e)
    {
      delete[] dynamArr;
      std::cerr << "Out of memory!" << '\n';
      return 1;
    }
  }
  if (!ivanova::input_matrix(input, matrix, m, n, read) || read != (m * n))
  {
    delete[] dynamArr;
    std::cerr << "Invalid input" << "\n";
    return 2;
  }

  output << ivanova::num_col_lsr(matrix, m, n) << '\n';

  output << ivanova::min_sum_mdg(matrix, m, n) << '\n';
  delete[] dynamArr;
}
