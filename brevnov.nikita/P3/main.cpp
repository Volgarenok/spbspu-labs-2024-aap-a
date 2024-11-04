#include <fstream>
#include "matrix.hpp"
#include "find_osed.hpp"


int main(int argc, char ** argv)
{
  int long long m = -1, n = -1;
  int testmode = -1;
  int auxiliary_array[10000] = {};
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
  char * forptr = nullptr;
  testmode = std::strtol(argv[1], &forptr, 10);
  if (testmode == -1)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if ((testmode < 1) || (testmode > 2))
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
    std::cerr << "Non-correct matrix parameter\n";
    return 2;
  }
  int * mtx = nullptr;
  if (testmode == 1)
  {
    mtx = auxiliary_array;
  }
  else
  {
    try
    {
      mtx = new int[m*n];
    }
    catch(const std::bad_alloc& e)
    {
      std::cerr << "Not enough memory\n";
      return 2;
    }
  }
  int saved_values = brevnov::input_matrix(input, mtx, m, n);
  if (saved_values != m * n)
  {
    std::cerr << "Error matrix input\n";
    if (testmode == 2)
    {
      delete[] mtx;
    }
    return 2;
  }
  output << brevnov::find_osed(mtx, m, n);
  output << "\n";
  if (testmode == 2)
  {
    delete[] mtx;
  }
  return 0;
}
