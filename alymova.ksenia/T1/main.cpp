#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "inputProcess.hpp"

int main()
{
  constexpr int max_size = 1000;
  alymova::Shape* shapes[max_size] = {};
  int shapes_now = 0;
  double scale_x = 0.0;
  double scale_y = 0.0;
  double ratio = 2;
  bool flag = false;
  //shapes[0] = alymova::makeShape(std::cin, shapes, shapes_now, flag, scale_x, scale_y, ratio);
  alymova::Circle circle(alymova::point_t(2.0, 3.0), 15.0);
  shapes[0] = &circle;
  shapes_now++;
  std::cout << shapes[0]->getArea();
  /*print(std::cout, shapes);
  std::cout << "\n";
  scale(shapes, alymova::point_t(scale_x, scale_y), ratio);
  print(std::cout, shapes);
  std::cout << "\n";*/
  clear(shapes);
}

