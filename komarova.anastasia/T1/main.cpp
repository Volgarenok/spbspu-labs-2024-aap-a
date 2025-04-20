#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "make_shapes.hpp"

int main()
{
  constexpr int size = 100000;
  komarova::Shape* shapes[size] = {};
  bool wrong_shape = false;
  size_t count = 0;
  double x_sc = 0.0;
  double y_sc = 0.0;
  double coef = 1.0;
  try
  {
    komarova::makeShapes(std::cin, shapes, wrong_shape, count, x_sc, y_sc, coef);
    if (count == 0)
    {
      std::cerr << "nothig to scale \n";
      return 1;
    }
    std::cout << std::fixed << std::setprecision(1);
    komarova::sumArea(std::cout, shapes);
    komarova::getFramerectXY(std::cout, shapes);
    std::cout << "\n";
    komarova::point_t scale_xy = {x_sc, y_sc};
    komarova::scale(shapes, scale_xy, coef);
    komarova::sumArea(std::cout, shapes);
    komarova::getFramerectXY(std::cout, shapes);
    std::cout << "\n";
    if (wrong_shape)
    {
      std::cerr << "incorrect shape \n";
    }
    komarova::deleteShapes(shapes);
  }
  catch (const std::exception& e)
  {
    deleteShapes(shapes);
    std::cerr << e.what() << '\n';
    return 1;
  }
}
