#include "shape.hpp"
#include <string>
#include "rectangle.hpp"

maslevtsov::Shape* maslevtsov::makeShape(std::istream& in)
{
  std::string figureName = "";
  in >> figureName;

  if (figureName == "RECTANGLE")
  {
    double bottomLeftX = 0, bottomLeftY = 0, topRightX = 0, topRightY = 0;
    in >> bottomLeftX >> bottomLeftY >> topRightX >> topRightY;
    Rectangle rect(point_t{bottomLeftX, bottomLeftY}, point_t{topRightX, topRightY});
    return &rect;
  }
  throw std::logic_error("not supported");
}
