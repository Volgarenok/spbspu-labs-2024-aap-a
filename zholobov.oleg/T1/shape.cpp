#include "shape.hpp"

#include <iostream>
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"

void zholobov::print_shapes(Shape** shapes, size_t shape_cnt)
{
  float total_area = 0.0f;
  for (size_t i = 0; i < shape_cnt; ++i) {
    total_area += shapes[i]->getArea();
  }

  std::cout << total_area;
  for (size_t i = 0; i < shape_cnt; ++i) {
    rectangle_t rect = shapes[i]->getFrameRect();
    std::cout << " " << rect.pos.x - rect.width / 2.0f << " " << rect.pos.y - rect.height / 2.0f;
    std::cout << " " << rect.pos.x + rect.width / 2.0f << " " << rect.pos.y + rect.height / 2.0f;
  }
  std::cout << "\n";
}
