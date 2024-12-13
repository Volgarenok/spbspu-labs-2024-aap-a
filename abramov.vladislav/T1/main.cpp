#include <iostream>
#include <string>
#include <iomanip>
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
  if (i == 0)
  {
    std::cerr << "There is no figures\n";
    return 1;
  }
  if (k <= 0)
  {
    abramov::deleteShapes(shapes, i);
    std::cerr << "There is no scale command\n";
    return 1;
  }
  double s = 0;
  std::cout << std::fixed << std::setprecision(1);
  for (size_t j = 0; j < i; ++j)
  {
    s += shapes[j]->getArea();
    rects[j] = shapes[j]->getFrameRect();
  }
  std::cout << s << " ";
  abramov::point_t p;
  p.x = x;
  p.y = y;
  for (size_t j = 0; j < i - 1; ++j)
  {
    abramov::printFrameRectCoords(rects[j]);
    std::cout << " ";
    abramov::scaleFigure(shapes[j], p, k);
  }
  abramov::printFrameRectCoords(rects[i - 1]);
  abramov::scaleFigure(shapes[i - 1], p, k);
  std::cout << "\n";
  s = 0;
  for (size_t j = 0; j < i; ++j)
  {
    s += shapes[j]->getArea();
    rects[j] = shapes[j]->getFrameRect();
  }
  std::cout << s << " ";
  for (size_t j = 0; j < i - 1; ++j)
  {
    abramov::printFrameRectCoords(rects[j]);
    std::cout << " ";
  }
  abramov::printFrameRectCoords(rects[i - 1]);
  std::cout << "\n";
  if (wrong_figure == true)
  {
    std::cerr << "There was bad figure\n";
  }
  abramov::deleteShapes(shapes, i);
}
