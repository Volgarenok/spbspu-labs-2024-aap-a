#include <iostream>
#include <string>
#include <getString.hpp>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"
#include "shape_transformations.hpp"

int main()
{
  using namespace abramov;

  CompositeShape shapes(10000);
  double k = 0;
  bool wrong_figure = false;
  point_t p{0.0, 0.0};
  try
  {
    getShapes(std::cin, shapes, p, k, wrong_figure);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  size_t count = shapes.getShapes_();
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
  printShapes(std::cout, shapes, p, k, count);
  if (wrong_figure == true)
  {
    std::cerr << "There was bad figure\n";
  }
}
