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
  for (size_t i = 0; argv[1][i] != '\0'; i++)
  {
    if (!hismatova::is_digit(argv[1][i]))
    {
      std::cerr << "first argv must be digit\n";
      return 1;
    }
  }
  std::ifstream in_par(argv[2]);
  if (!in_par)
  {
    std::cerr << "failed to open input file\n";
    return 1;
  }
  std::ofstream out_par(argv[3]);
  const int parametr = atoi(argv[1]);
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
  if (parametr == 1)
  {
    if (m * n > 1000)
    {
      std::cerr << "too many elements\n";
      return 1;
    }
    int matrix[1000];
    if (!hismatova::input_matrix(in_par, matrix, m, n, read))
    {
      std::cerr << "input matrix failed\n";
      return 1;
    }
    if (read < m * n)
    {
      std::cerr << "not enough elements\n";
      return 1;
    }
    hismatova::output_result(out_par, matrix, m, n);
  }
  else if (parametr == 2)
  {
    int * matrix = new int[m * n];
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
    hismatova::output_result(out_par, matrix, m, n);
    delete[] matrix;
  }
  else
  {
    std::cerr << "first argv is wrong\n";
    return 1;
  }
  return 0;
}
