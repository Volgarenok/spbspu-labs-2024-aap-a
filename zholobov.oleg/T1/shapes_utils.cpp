#include "shapes_utils.hpp"
#include <iostream>
#include <iomanip>
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"

zholobov::Rectangle* zholobov::create_rectangle(std::istream& in)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  if (!in || x2 <= x1 || y2 <=y1) {
    throw std::invalid_argument("Error in RECTANGLE parameters");
  }
  return new Rectangle({x1, y1}, {x2, y2});
}

zholobov::Square* zholobov::create_square(std::istream& in)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double a;
  in >> x1 >> y1 >> a;
  if (!in || a <= 0) {
    throw std::invalid_argument("Error in SQUARE parameters");
  }
  return new Square(zholobov::point_t{x1, y1}, double{a});
}

zholobov::Parallelogram* zholobov::create_parallelogram(std::istream& in)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  bool correct_parallelogram = (y1 == y2 && y1 != y3) || (y2 == y3 && y1 != y2);
  if (!in || !correct_parallelogram) {
    throw std::invalid_argument("Error in PARALLELOGRAM parameters");
  }
  return new zholobov::Parallelogram(
      zholobov::point_t{x1, y1},
      zholobov::point_t{x2, y2},
      zholobov::point_t{x3, y3});
}

void zholobov::process_scale(Shape** shapes, size_t shape_cnt, point_t pos, double scale_factor)
{
  zholobov::print_shapes(shapes, shape_cnt);
  for (size_t i = 0; i < shape_cnt; ++i) {
    if (shapes[i]) {
      shapes[i]->scale(scale_factor);
      zholobov::rectangle_t rect = shapes[i]->getFrameRect();
      zholobov::point_t new_pos;
      new_pos.x = (rect.pos.x - pos.x) * scale_factor + pos.x;
      new_pos.y = (rect.pos.y - pos.y) * scale_factor + pos.y;
      shapes[i]->move(new_pos);
    }
  }
  zholobov::print_shapes(shapes, shape_cnt);
}

void zholobov::print_shapes(Shape** shapes, size_t shape_cnt)
{
  double total_area = 0.0;
  for (size_t i = 0; i < shape_cnt; ++i) {
    if (shapes[i]) {
      total_area += shapes[i]->getArea();
    }
  }
  std::cout << std::fixed << std::setprecision(1) << total_area;
  for (size_t i = 0; i < shape_cnt; ++i) {
    if (shapes[i]) {
      rectangle_t rect = shapes[i]->getFrameRect();
      std::cout << " " << rect.pos.x - rect.width / 2.0f << " " << rect.pos.y - rect.height / 2.0f;
      std::cout << " " << rect.pos.x + rect.width / 2.0f << " " << rect.pos.y + rect.height / 2.0f;
    }
  }
  std::cout << "\n";
}

void zholobov::delete_shapes(Shape** shapes, size_t shape_cnt)\
{
  for (size_t i = 0; i < shape_cnt; ++i) {
    delete shapes[i];
  }
}
