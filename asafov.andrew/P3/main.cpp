#include <iostream>
#include <fstream>
#include <stdexcept>
#include "matrixAutoInitiallization.hpp"
#include "matrixDynamicInitiallization.hpp"
#include "matrixPush.hpp"
#include "matrixHandling.hpp"

int main(int argc, char** argv)
{
  if (argc < 4) {
    std::cerr << "Not enough arguments";
    return 1;
  }
    else if (argc > 4) {
    std::cerr << "Too many arguments";
    return 1;
  }
  else if (argv[1][0] == '1')
  {
    int mtx[10000] = {};
    int a[2] = {};
    try
    {
      asafov::matrixAutoInitialization(mtx, argv[2], a[0], a[1]);
    }
    catch (const std::logic_error & e)
    {
      return 2;
    }
    asafov::matrixPush(asafov::matrixHandlingSanctions(mtx, a[0], a[1]), argv[3]);
  }
  else if (argv[1][0] == '2')
  {
    int* mtx = nullptr;
    int a[2] = {};
    try
    {
      asafov::matrixDynamicInitialization(mtx, argv[2], a[0], a[1]);
    }
    catch (const std::logic_error & e)
    {
      delete[] mtx;
      return 2;
    }
    asafov::matrixPush(asafov::matrixHandlingSanctions(mtx, a[0], a[1]), argv[3]);
    delete[] mtx;
  }
  else
  {
    std::cerr << "First parameter is not a number";
    return 1;
  }
  return 0;
}
