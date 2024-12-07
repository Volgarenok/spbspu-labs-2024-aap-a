#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include <cstddef>
#include "matrixInitiallization.hpp"
#include "matrixOutput.hpp"
#include "matrixHandling.hpp"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments";
    return 1;
  }
  else if (argv[1][0] == '1' && argv[1][1] == 0)
  {
    int mtx[10000] = {};
    unsigned long long a[2] = {0, 0};
    std::ifstream fin(argv[2]);
    fin >> a[0];
    fin >> a[1];
    if (fin.fail() || fin.eof())
    {
      return 1;
    }
    try
    {
      asafov::initializeMatrix(fin, mtx, a[0], a[1]);
    }
    catch (const std::logic_error & e)
    {
      return 2;
    }
    std::ofstream fout(argv[3]);
    fout << asafov::handleNumColLsr(mtx, a[0], a[1]);
  }
  else if (argv[1][0] == '2' && argv[1][1] == 0)
  {
    unsigned long long a[2] = {0, 0};
    std::ifstream fin(argv[2]);
    fin >> a[0];
    fin >> a[1];
    if (fin.fail() || fin.eof())
    {
      return 1;
    }
    int* mtx = new int[a[0] * a[1]];
    try
    {
      asafov::initializeMatrix(fin, mtx, a[0], a[1]);
    }
    catch (const std::logic_error & e)
    {
      delete[] mtx;
      return 2;
    }
    std::ofstream fout(argv[3]);
    fout << asafov::handleNumColLsr(mtx, a[0], a[1]);
    delete[] mtx;
  }
  else
  {
    std::cerr << "First parameter is not a number";
    return 1;
  }
  return 0;
}
