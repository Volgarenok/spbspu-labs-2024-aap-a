#include "shape.hpp"

#include <iostream>
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"

void zholobov::print_shapes(Shape** shapes, size_t shape_cnt)
{
  for (size_t i = 0; i < shape_cnt; ++i) {
    std::cout << shapes[i]->getArea() << " ";
    rectangle_t rect = shapes[i]->getFrameRect();
    std::cout << rect.pos.x - rect.width / 2.0f << " " << rect.pos.y - rect.height / 2.0f << " ";
    std::cout << rect.pos.x + rect.width / 2.0f << " " << rect.pos.y + rect.height / 2.0f << "\n";
  }
}
