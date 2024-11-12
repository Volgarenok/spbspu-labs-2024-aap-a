#include "matrix.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "wrong count of argc\n";
    return 1;
  }
  if (!(argv[1][0] == 1 || argv[1][0] != 2))
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
  const int parametr = std::atoi(argv[1]);
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
  if (parametr == 1)
  {
    if (m * n > 1000)
    {
      std::cerr << "too many elements\n";
      return 1;
    }
    matrix = new int[1000];
  }
  else
  {
    matrix = new int[m * n];
  }
  if (!hismatova::input_matrix(in_par, matrix, m, n, read))
  {
    std::cerr << "input matrix failed\n";
    delete[] matrix;
    return 1;
  }
  if (read < m * n)
  {
    std::cerr << "not enough elements\n";
    delete[] matrix;
    return 1;
  }
  out_par << hismatova::find_longest(matrix, m, n) << "\n";
  delete[] matrix;
  return 0;
}
