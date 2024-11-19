#include "matrixDynamicInitiallization.hpp"
#include <fstream>
#include <stdexcept>

void asafov::matrixDynamicInitialization(int*& mtx, char* input, size_t& n, size_t& m)
{
  std::ifstream fin(input);
  fin >> n;
  if (fin.fail() || fin.eof()) {
    throw std::logic_error("err");
    fin.close();
  }
  fin >> m;
  if (fin.fail() || fin.eof()) {
    throw std::logic_error("err");
    fin.close();
  }
  mtx = new int[n * m];
  for (size_t i = 0; i < n * m; i++) {
    fin >> mtx[i];
    if (fin.fail() || fin.eof()) {
      throw std::logic_error("err");
      fin.close();
    }
  }
  fin.close();
}
