#include <string>
#include <iostream>
#include "input.hpp"
#include "output.hpp"
#include "shape.hpp"
#include "compositeShape.hpp"
int main()
{
  using namespace karnauhova;
  point_t point{0, 0};
  double k = 0;
  bool flag = 0;
  CompositeShape shaps(1);
  std::string name = "uwu";
  while (std::cin >> name && !std::cin.eof())
  {
    try
    {
      fabric_input(std::cin, shaps, point, k, name);
    }
    catch (const std::logic_error& e)
    {
      std::cin.clear();
      flag = true;
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Out of memmory\n";
      return 1;
    }
  }
  if (shaps.size() == 0)
  {
    std::cerr << "Error: empty input\n";
    return 1;
  }
  if (k <= 0)
  {
    std::cerr << "Error: scale input\n";
    return 1;
  }
  if (flag)
  {
    std::cerr << "Error in input!\n";
  }
  output(std::cout, shaps, point, k);
}

