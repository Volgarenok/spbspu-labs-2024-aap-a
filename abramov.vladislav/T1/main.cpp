#include <iostream>
#include <string>
#include <getString.hpp>
#include "base-types.hpp"
#include "shape_transformations.hpp"

int main()
{
  using namespace abramov;

  CompositeShape shapes(0);
  double k = 0;
  bool wrong_figure = false;
  point_t p{0.0, 0.0};
  try
  {
    getShapes(std::cin, shapes, p, k, wrong_figure);
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  size_t count = shapes.size();
  if (k <= 0)
  {
    std::cerr << "There is no scale command\n";
    return 1;
  }
  if (count == 0)
  {
    std::cerr << "There is no figures\n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  printShapes(std::cout, shapes);
  scaleFigures(shapes, p, k);
  printShapes(std::cout, shapes);
  if (wrong_figure)
  {
    std::cerr << "There was bad figure\n";
  }
}
