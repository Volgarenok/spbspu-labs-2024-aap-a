#include <iostream>
#include <fstream>
#include <istream>
#include <cstddef>
#include <stdexcept>
#include "is3Angle.hpp"
#include "checkEnter.hpp"
#include "enterMTX.hpp"

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
  if (!input) {
    std::cerr << "Error with matrix's size\n";
    return 2;
  }
  int * mtx = nullptr;
  if (secondArg == 1) {
    int redmtx[10000] = {};
    mtx = redmtx;
  }
  if (secondArg == 2) {
    try {
      mtx = new int[m*n];
   } catch(const std::bad_alloc & e) {
     std::cerr << "Error with make matrix\n";
     return 2;
   }
  }
  size_t readed = 0;
  dribas::enterMTX(input, mtx, m, n, readed);
  if (input && readed == m * n){
    if (dribas::is3Angle(mtx, m, n)) {
      output << "true" << "\n";
    } else {
      output << "false" << "\n";
    }
  } else {
    std::cerr << "Error with enter\n";
    if (secondArg == 2) {
      delete[] mtx;
    }
    return 2;
  }
  if (secondArg == 2) {
    delete[] mtx;
  }
  return 0;
}
