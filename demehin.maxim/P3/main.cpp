#include <iostream>
#include <fstream>
#include "cnt_row_nsm.h"
#include "matrix_funcs.h"

int main(int argc, char** argv)
{
  int l = argc;
  if (l < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (l > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  char* f = argv[1];
  int c = *f - '0';
  if (f[0] < 48 || f[0] > 57)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (f[1] != '\0' || (c > 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t m = 0, n = 0, k = 0;
  input >> m >> n;
  k = m * n;
  int* matrix = nullptr;
  try
  {
    matrix = demehin::alloc(k, c);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  size_t read = 0;
  if(!demehin::input_matrix(input, matrix, k, read) && m != 0)
  {
    std::cerr << "Impossible to build matrix\n";
    return 2;
  }
  if(!std::cin)
  if (read != k)
  {
    std::cerr << "Impossible to build matrix due incorrect element\n";
    return 2;
  }
  std::cout << demehin::cnt_row_nsm(matrix, n, m ) << "\n";
  for (size_t i = 0; i < k; ++i)
  {
    std::cout << matrix[i] << "\n";
  }
  std::ofstream output(argv[3]);
}


