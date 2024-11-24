#include <iostream>
#include <fstream>
#include <cstdlib>
#include "mtx_transform.hpp"
namespace nikonov
{
  bool inputCheck(int argc, char** argv)
  {
    if (argc < 4)
    {
      std::cerr << "Not enough arguments\n";
      return 0;
    }
    else if (argc > 4)
    {
      std::cerr << "Too many arguments\n";
      return 0;
    }
    if (!std::atoi(argv[1]) || argv[1][1] != '\0')
    {
      std::cerr << "First parameter is not a number\n";
      return 0;
    }
    if (argv[1][0] != '1' && argv[1][0] != '2')
    {
      std::cerr << "First parameter is not a correct number\n";
      return 0;
    }
    return 1;
  }
}
int main(int argc, char ** argv)
{
  if (!nikonov::inputCheck(argc, argv))
  {
    return 1;
  }
  std::ifstream input(argv[2]);

  size_t m = 0;
  size_t n = 0;
  input >> m;
  input >> n;
  size_t read = 0;
  int* arrUni = nullptr;
  int stackBuffer[1000] = { 0 };
  if (std::atoi(argv[1]) == 1)
  {
    arrUni = stackBuffer;
  }
  else
  {
    try
    {
      arrUni = new int[m * n];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "ERROR: " << e.what() << "\n";
      return 1;
    }
  }
  if (!nikonov::readMatrix(input, arrUni, m, n, read))
  {
    std::cerr << "ERROR: incorrect input\n";
    if (std::atoi(argv[1]) == 2)
    {
      delete[] arrUni;
    }
    return 2;
  }
  nikonov::spiralMtxReduction(arrUni, m, n);
  std::ofstream output(argv[3]);
  nikonov::printMatrix(output, arrUni, m, n);
  if (std::atoi(argv[1]) == 2)
  {
    delete[] arrUni;
  }
}
