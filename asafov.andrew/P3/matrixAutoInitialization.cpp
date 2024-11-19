#include "matrixAutoInitiallization.hpp"
#include <fstream>
#include <stdexcept>

void asafov::matrixAutoInitialization(int* mtx, char* input, size_t& n, size_t& m)
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
  for (size_t i = 0; i < n * m; i++) {
    fin >> mtx[i];
    if (fin.fail() || fin.eof()) {
      throw std::logic_error("err");
      fin.close();
    }
  }
  fin.close();
}
