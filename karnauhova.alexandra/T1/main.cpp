#include "input.hpp"
#include "shape.hpp"
#include "count_point.hpp"
#include <string>
#include <iostream>

int main()
{
  std::string names[5000] = {};
  double* points = nullptr;
  try
  {
    points = new double[10000];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] points;
    std::cerr << "Out of memmory\n";
  }
  karnauhova::input(std::cin, points, names);
  std::cout << points[4] << names[1] << "\n";
}
