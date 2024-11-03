#include <iostream>
#include <fstream>
#include <cstring>

#include "cmdprotection.hpp"
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
  size_t m = 0;
  size_t n = 0;
  std::ifstream inf(argv[2]);
  std::ifstream outf(argv[3]);
  inf >> n >> m;
  if (!inf)
  {
    return 2;
  }
  size_t general = m * n;
  size_t read = 0;
  if (argv[1][0] == 1)
  {
    int arr[10000];
    if (!inputMtx(inf, arr, general, read) || (read != general))
    {
      return 2;
    }
    outf << searchNumLogMin(arr, general) << "\n";
  }
  else
  {
    int *arr = nullptr;
    try
    {
      arr = new int[general];
    }
    catch (const std::logic_error &e)
    {
      return 2;
    }
    if (!inputMtx(inf, arr, general, read) || (read != general))
    {
      return 2;
    }
    outf << searchNumLogMin(arr, general) << "\n";
  }
}
