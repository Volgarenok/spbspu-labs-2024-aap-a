#include "shapes_utils.hpp"

#include "parallelogram.hpp"
#include "rectangle.hpp"
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
  throw std::invalid_argument("Unknown shape");
}
