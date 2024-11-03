#include "matrix.hpp"
#include <fstream>

int main(int argc, char ** argv)
{
  int long long m = -1, n = -1;
  int parameter = 0;
  char * forptr = nullptr;
  int helpmas[10000] = {};
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  parameter = std::strtol(argv[1], &forptr, 10);
  if (!(parameter))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if ((parameter < 1) || (parameter > 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  input >> m >> n;
  if (input.eof())
  {
    std::cerr << "Not enough elements in file\n";
    return 2;
  }
  if ((m < 0) || (n < 0))
  {
    std::cerr << "Non-correct matrix parameters\n";
    return 2;
  }
  int * mtx = nullptr;
  if (parameter == 1)
  {
    mtx = helpmas;
  }
  else
  {
    try
    {
      mtx = brevnov::alloc(m, n);
    }
    catch(const std::bad_alloc& e)
    {
      std::cerr << "Not enough memory\n";
      return 2;
    }
  }
  int member = brevnov::input_matrix(input, mtx, m, n);
  if (!(member == m * n))
  {
    std::cerr << "Error matrix input\n";
    if (parameter == 2)
    {
      delete[] mtx;
    }
    return 2;
  }
  output << brevnov::osed_fun(mtx, m, n);
  if (parameter == 2)
  {
    delete[] mtx;
  }
  return 0;
}
