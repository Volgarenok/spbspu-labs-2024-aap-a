#include <iostream>
#include <string>

#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"

int main()
{
  constexpr size_t max_shapes = 1000;
  zholobov::Shape* shapes[max_shapes];
  size_t shape_cnt = 0;
  std::string shape_name;
  while (std::cin >> shape_name) {
    if (shape_name == "RECTANGLE") {
      float x1;
      float y1;
      float x2;
      float y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      if (std::cin) {
        shapes[shape_cnt++] = new zholobov::Rectangle(zholobov::point_t{x1, y1}, zholobov::point_t{x2, y2});
      }
    } else if (shape_name == "SQUARE") {
      float x1;
      float y1;
      float a;
      std::cin >> x1 >> y1 >> a;
      if (std::cin) {
        shapes[shape_cnt++] = new zholobov::Square(zholobov::point_t{x1, y1}, float{a});
      }
    } else if (shape_name == "PARALLELOGRAM") {
      float x1;
      float y1;
      float x2;
      float y2;
      float x3;
      float y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (std::cin) {
        shapes[shape_cnt++] = new zholobov::Parallelogram(
            zholobov::point_t{x1, y1},
            zholobov::point_t{x2, y2},
            zholobov::point_t{x3, y3});
      }
    } else if (shape_name == "SCALE") {
      float x;
      float y;
      float k;
      std::cin >> x >> y >> k;
      if (!std::cin || k <= 0) {
        std::cerr << "Error processing SCALE parameters\n";
        return 1;
      }
      zholobov::print_shapes(shapes, shape_cnt);
      for (size_t i = 0; i < shape_cnt; ++i) {
        shapes[i]->scale(k);
        zholobov::rectangle_t rect = shapes[i]->getFrameRect();
        zholobov::point_t new_pos;
        new_pos.x = (rect.pos.x - x) * k + x;
        new_pos.y = (rect.pos.y - y) * k + y;
        shapes[i]->move(new_pos);
      }
      zholobov::print_shapes(shapes, shape_cnt);
    } else {
      std::cerr << "Unknown shape (" << shape_name << ")\n";
    }
  }
  for (size_t i = 0; i < shape_cnt; ++i) {
    delete shapes[i];
  }
  return 0;
}
