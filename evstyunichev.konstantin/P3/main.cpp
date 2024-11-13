#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char **argv)
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
  size_t n = 0, m = 0;
  fin >> n >> m;
  if (!fin)
  {
    std::cout << "((\n";
    return 1;
  }
  int p = 0;
  p = evstyunichev::CastToDigit(argv[1]);
  if (!p)
  {
    std::cerr << "is not 1 or 2 btw\n";
    return 1;
  }
  int num = p;
  int *arr = nullptr, *d_arr = nullptr;
  if (num == 1)
  {
    static int static_arr[StaticArrSize];
    arr = static_arr;
  }
  else if(num == 2)
  {
    try
    {
      d_arr = new int[n * m];
      arr = d_arr;
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << "\n";
      delete[] d_arr;
      return 1;
    }
  }
  size_t read = 0;
  if (evstyunichev::Input(fin, arr, n, m, read) && (read == n * m) && (read))
  {
    fout << evstyunichev::CntRowsNsm(arr, n, m) << "\n";
  }
  else
  {
    delete[] d_arr;
    return 2;
  }
  delete[] d_arr;
  return 0;
}
