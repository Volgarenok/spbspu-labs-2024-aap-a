#include <iostream>
#include <stdexcept>
#include "base_types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"
#include "square.hpp"
#include "make_shapes.hpp"

int main()
{
  constexpr int size = 100000;
  komarova::Shape* shapes[size] = {};
  int count = 0;
  double x_sc = 0.0;
  double y_sc = 0.0;
  double coef = 1.0;
  bool wrong_shape = false;

  try
  {
    лщьфкщмф::make_shapes(std::cin, shapes, count, wrong_shape, x_sc, y_sc, coef);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "No memory allocated \n";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    delete_shapes(shapes);
    std::cerr << e.what() << "\n";
    return 1;
  }

  if (coef <= 0)
  {
    delete_shapes(shapes);
    std::cerr << "incorrect coefficient \n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << komarova::area_sum(std::cout, shapes);
  komarova::frame_rect_xy(std::cout, shapes);
  std::cout << "\n";
  komarova::point_t scale_xy = {x_sc, y_sc};
  komarova::scale(shapes, scale_xy, coef);
  std::cout << komarova::area_sum(std::cout, shapes);
  komarova::frame_rect_xy(std::cout, shapes);
  std::cout << "\n";
  if (wrong_shape)
  {
    std::cerr << "incorrect shape \n";
  }
  komarova::delete_shapes(shapes);
}

