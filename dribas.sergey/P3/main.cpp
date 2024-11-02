#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "is3Angle.hpp"
#include "makeMatrix.hpp"
#include "checkEnter.hpp"

int main(int argc, char ** argv)
{
  long int secondArg = -1;
  if (!dribas::checkEnter(argv, argc, secondArg)) {
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);

  size_t m = 0, n = 0;
  input >> m >> n;
  if (!input || m == 0 || n == 0) {
    std::cerr << "Error with matrix's size\n";
    return 2;
  }
  int * mtx = nullptr;
  if (!dribas::makeMatrix(secondArg, mtx, m, n)) {
    std::cerr << "Error with create matrix\n";
    return 2;
  }

  return 0;
}
