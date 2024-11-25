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
    try
    {
      asafov::initializationMatrix(fin, mtx, a[0], a[1]);
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
    int* mtx = nullptr;
    unsigned long long a[2] = {0, 0};
    std::ifstream fin(argv[2]);
    try
    {
      fin >> a[0];
      if (fin.fail() || fin.eof()) {
        throw std::logic_error("err");
      }
      fin >> a[1];
      if (fin.fail() || fin.eof()) {
        throw std::logic_error("err");
      }
      asafov::initializationMatrix(fin, mtx, a[0], a[1]);
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
