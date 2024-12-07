#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.h"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "wrong count of argc\n";
    return 1;
  }
  int parametr = std::atoi(argv[1]);
  if ((parametr != 1 && parametr != 2) || argv[1][1] != '\0')
  {
    std::cerr << "first argv is wrong\n";
    return 1;
  }
  std::ifstream in_par(argv[2]);
  if (!in_par)
  {
    std::cerr << "failed to open input file\n";
    return 1;
  }
  std::ofstream out_par(argv[3]);
  size_t m = 0;
  size_t n = 0;
  in_par >> m >> n;
  if (!in_par)
  {
    std::cout << "wrong file\n";
    return 1;
  }
  out_par << m << " " << n << "\n";
  size_t read = 0;
  int* matrix = nullptr;
  int* dynamic_matrix = nullptr;
  int matrix1[10000] = {0};
  if (parametr == 1)
  {
    if (m * n > 10000)
    {
      std::cerr << "too many elements\n";
      return 1;
    }
    matrix = matrix1;
  }
  else
  {
    dynamic_matrix = new int[m * n];
    matrix = dynamic_matrix;
  }
  if (!hismatova::input_matrix(in_par, matrix, m, n, read))
  {
    std::cerr << "input matrix failed\n";
    delete[] dynamic_matrix;
    return 1;
  }
  if (read < m * n)
  {
    std::cerr << "not enough elements\n";
    delete[] dynamic_matrix;
    return 1;
  }
  out_par << hismatova::find_longest(matrix, m, n) << "\n";
  delete[] dynamic_matrix;
  return 0;
}
