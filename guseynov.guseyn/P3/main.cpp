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
  std::ifstream input(argv[2]);
  std::ifstream output(argv[3]);
  input >> n >> m;
  if (!input)
  {
    return 2;
  }
  size_t general = m * n;
  size_t read = 0;
  if (argv[1][0] == 1)
  {
    int arr[10000];
    if (!inputMtx(input, arr, general, read) || (read != general))
    {
      return 2;
    }
    output << searchNumLogMin(arr, general) << "\n";
  }
  else
  {
    if (argv[1][0] == 0)
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
      if (!inputMtx(input, arr, general, read) || (read != general))
      {
        return 2;
      }
      output << searchNumLogMin(arr, general) << "\n";
    }
  }
}
