#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char** argv)
{
  constexpr size_t StaticArrSize = 1e4;
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  std::ifstream fin(argv[2]);
  std::ofstream fout(argv[3]);
  size_t m = 0, n = 0;
  fin >> m >> n;
  if (!fin)
  {
    std::cout << "((\n";
    return 1;
  }
  if ((cstring_len(argv[1]) == 1))
  {
    int num = 0;
    num = atoi(argv[1]);
    int* arr = nullptr;
    if (num == 1)
    {
      int static_arr[StaticArrSize];
      arr = static_arr;
    }
    else if(num == 2)
    {
      try
      {
        int* d_arr = new int[m * n];
        arr = d_arr;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << "\n";
        ddel(arr, num);
        return 1;
      }
    }
    else
    {
      std::cerr << "out of range\n";
      return 1;
    }
    size_t read = 0;
    if (input(fin, arr, m, n, read) && (read == n * m))
    {
      std::cout << CntRowsNsm(arr, m, n) << "\n";
    }
    else
    {
      ddel(arr, num);
      return 2;
    }
    ddel(arr, num);
  }
  else
  {
    std::cout << "is not 1 or 2\n";
  }
  return 0;
}
