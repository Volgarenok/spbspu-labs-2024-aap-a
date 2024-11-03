#include <iostream>
#include <fstream>
#include "filemtx.h"
#include "mtxlogic.h"

int main(int argc, char** argv)
{
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
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  const char * number = argv[1];
  int id = 0;
  if (!(tkach::isNumber(number)))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  id = atoi(number);
  if ((id != 1) && (id != 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  size_t str = 0, stl = 0;
  input >> str >> stl;
  if (!input)
  {
    std::cerr << "ERROR: incorrect str/stl value\n";
    return 1;
  }
  if (str == 1 && stl == 1)
  {
    std::cerr << "ERROR: no other elements\n";
    return 1;
  }
  if (id == 1)
  {
    int mtx[10000] = {0};
    if (!(tkach::inputMtx(input, mtx, str, stl)))
    {
      std::cerr << "ERROR: Invalid input\n";
      return 2;
    }
    tkach::outputMtx(output, tkach::createMtx2(mtx, str, stl), str, stl);
    output << "\n";
  }
  else if (id == 2)
  {
    int* mtx = nullptr;
    try
    {
      mtx = new int[str * stl];
    }
    catch(const std::bad_alloc & e)
    {
      delete[] mtx;
      std::cerr << "Out of memory\n";
      return 1;
    }
    if (!(tkach::inputMtx(input, mtx, str, stl)))
    {
      delete[] mtx;
      std::cerr << "ERROR: Invalid input\n";
      return 2;
    }
    tkach::outputMtx(output, tkach::createMtx2(mtx, str, stl), stl, stl);
    output << "\n";
    delete[] mtx;
  }
  return 0;
}
