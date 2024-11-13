#include <iostream>
#include <fstream>
#include "input_output_matrix.hpp"
#include "find_osed.hpp"
#include "fll_inc_wav.hpp"
#include "intcheck.hpp"

int main(int argc, char ** argv)
{
  int long long m = -1, n = -1;
  int testmode = 0;
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
  try
  {
    testmode = brevnov::intcheck(argv[1]);
  }
  catch (const std::invalid_argument& e)
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
  if ((m == 0) || (n == 0))
  {
    output << "0\n";
    output << "0 0\n";
    return 0;
  }
  int * mtx = nullptr;
  int * help_array = nullptr;
  if (testmode == 1)
  {
    mtx = auxiliary_array;
  }
  else
  {
    try
    {
      mtx = new int[m * n];
      help_array = mtx;
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Not enough memory\n";
      return 2;
    }
  }
  int saved_values = brevnov::input_matrix(input, mtx, m, n);
  if (saved_values != m * n)
  {
    std::cerr << "Error matrix input\n";
    delete[] help_array;
    return 2;
  }
  output << brevnov::find_osed(mtx, m, n);
  output << "\n";
  brevnov::fll_inc_wav(mtx, m, n);
  brevnov::output_matrix(output, mtx, m, n);
  output << "\n";
  delete[] help_array;
  return 0;
}
