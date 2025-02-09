#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char **argv)
{
  constexpr size_t fixedArrSize = 1e4;
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
  if (fin.fail())
  {
    std::cerr << "fail\n";
    return 1;
  }
  int num = evstyunichev::cast_to_digit(argv[1]);
  if (!num)
  {
    std::cerr << "is not 1 or 2 btw\n";
    return 1;
  }
  int *dArr = nullptr;
  size_t read = 0;
  if (num == 1)
  {
    int fixedArr[fixedArrSize];
    if (!evstyunichev::solve_print(fin, fout, fixedArr, n, m, read))
    {
      std::cerr << "bad input\n";
      return 2;
    }
  }
  else if (num == 2)
  {
    try
    {
      dArr = new int[n * m];
      if (!evstyunichev::solve_print(fin, fout, dArr, n, m, read))
      {
        std::cerr << "bad input\n";
        delete[] dArr;
        return 2;
      }
      delete[] dArr;
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << "\n";
      return 1;
    }
  }
  return 0;
}
