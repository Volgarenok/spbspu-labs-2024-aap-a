#include "shapes_utils.hpp"

#include <iomanip>
#include <iostream>

#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"

zholobov::Shape* zholobov::create_shape(const std::string& shape_name, std::istream& input_stream)
{
  if (shape_name == "RECTANGLE") {
    return zholobov::Rectangle::create(input_stream);
  } else if (shape_name == "SQUARE") {
    return zholobov::Square::create(input_stream);
  } else if (shape_name == "PARALLELOGRAM") {
    return zholobov::Parallelogram::create(input_stream);
  }
  return nullptr;
}

void zholobov::process_scale(Shape* const* shapes, size_t shape_cnt, point_t pos, double scale_factor)
{
  if (scale_factor <= 0.0) {
    throw std::invalid_argument("Invalid scale factor");
  }
  for (size_t i = 0; i < shape_cnt; ++i) {
    if (shapes[i]) {
      shapes[i]->scale_no_check(scale_factor);
      zholobov::rectangle_t rect = shapes[i]->getFrameRect();
      zholobov::point_t new_pos;
      new_pos.x = (rect.pos.x - pos.x) * scale_factor + pos.x;
      new_pos.y = (rect.pos.y - pos.y) * scale_factor + pos.y;
      shapes[i]->move(new_pos);
    }
  }
}

void zholobov::print_shapes(std::ostream& output, const Shape* const* shapes, size_t shape_cnt)
{
  double total_area = 0.0;
  for (size_t i = 0; i < shape_cnt; ++i) {
    if (shapes[i]) {
      total_area += shapes[i]->getArea();
    }
  }
  output << std::fixed << std::setprecision(1) << total_area;
  for (size_t i = 0; i < shape_cnt; ++i) {
    if (shapes[i]) {
      rectangle_t rect = shapes[i]->getFrameRect();
      output << " " << rect.pos.x - rect.width / 2.0 << " " << rect.pos.y - rect.height / 2.0;
      output << " " << rect.pos.x + rect.width / 2.0 << " " << rect.pos.y + rect.height / 2.0;
    }
  }
}

void zholobov::delete_shapes(Shape** shapes, size_t shape_cnt)
{
  for (size_t i = 0; i < shape_cnt; ++i) {
    delete shapes[i];
  }
}
