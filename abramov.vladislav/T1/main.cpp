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
  abramov::Shape *shapes[10000] = {};
  abramov::rectangle_t rects[10000] = {};
  size_t i = 0;
  double k = 0;
  double x = 0;
  double y = 0;
  bool wrong_figure = false;
  abramov::getShapes(std::cin, shapes, i, x, y, k, wrong_figure);
  if (k <= 0)
  {
    abramov::deleteShapes(shapes, i);
    std::cerr << "There is no scale command\n";
    return 1;
  }
  if (i == 0)
  {
    std::cerr << "There is no figures\n";
    return 1;
  }
  abramov::printShapes(std::cout, shapes, rects, i, x, y, k);
  if (wrong_figure == true)
  {
    std::cerr << "There was bad figure\n";
  }
  abramov::deleteShapes(shapes, i);
}
