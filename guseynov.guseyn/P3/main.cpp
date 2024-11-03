#include <iostream>
#include <fstream>
#include <cstddef>

#include "mtxprotection.hpp"
#include "matrix.hpp"

int main(int argc, char **argv)
{
  try
  {
    cmdProtection(argc, argv);
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what();
    return 1;
  }
  char a = ' ';
  char b = ' ';
  std::ifstream inf(argv[2]);
  std::ifstream outf(argv[3]);
  inf >> a >> b;
  try
  {
    mtxRangeProtection(a, b);
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what();
    return 1;
  }
  size_t m = static_cast < size_t > (a);
  size_t n = static_cast < size_t > (b);
  size_t general = m * n;
  size_t read = 0;
  int *arr = nullptr;
  if (argv[1][0] == 1)
  {
    int arr[10000];
  }
  else
  {
    try
    {
      int *arr = new int(general);
    }
    catch (const std::logic_error &e)
    {
      return 2;
    }
  }
  if (!inputMtx(inf, arr, general, read) || (read != general))
  {
    return 2;
  }
  outf << searchNumLogMin(arr, general) << "\n";
}
