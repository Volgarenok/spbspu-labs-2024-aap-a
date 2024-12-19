#include "string_manipulation.hpp"
#include "input_shape.hpp"
#include <stdexcept>
#include <string>
#include <cstring>
#include <ostream>
#include <iomanip>

void lanovenko::scaleCommand(const char* str, Shape* const* shapeArray, size_t shapeNumber, std::ostream& out)
{
  size_t linePosition = 0;
  const char* argumentOfStr = str + 6;
  double arguments[3]{};
  for (size_t i = 0; i < 3; i++)
  {
    arguments[i] = std::stod(argumentOfStr, std::addressof(linePosition));
    argumentOfStr += linePosition;
  }
  scaleShapes(shapeArray, shapeNumber, arguments, out);
}

void lanovenko::scaleShapes(Shape* const* shapeArray, size_t shapeNumber, const double* arguments, std::ostream& out)
{
  if (shapeNumber == 0)
  {
    throw std::logic_error("No parametrs to scale!\n");
  }
  if (arguments[2] < 0)
  {
    throw std::logic_error("Scale coeficient is negative!\n");
  }
  const point_t center = { arguments[0], arguments[1] };
  outputShapes(shapeArray, shapeNumber, out);
  for (size_t i = 0; i < shapeNumber; i++)
  {
    toScale(shapeArray[i], center, arguments[2]);
  }
  outputShapes(shapeArray, shapeNumber, out);
}

void lanovenko::toScale(Shape* shape, const point_t center, const double k)
{
  point_t start = shape->getFrameRect().pos;
  shape->move(center);
  point_t moved = shape->getFrameRect().pos;
  double dx = (moved.x - start.x) * k;
  double dy = (moved.y - start.y) * k;
  shape->unsScale(k);
  shape->move(-dx, -dy);
}

void lanovenko::outputShapes(const Shape* const* shapeArray, size_t shapeNumbers, std::ostream& out)
{
  double res = 0;
  for (size_t i = 0; i < shapeNumbers; i++)
  {
    res += shapeArray[i]->getArea();
  }
  out << std::fixed << std::setprecision(1);
  out << res;

  for (size_t i = 0; i < shapeNumbers; i++)
  {
    rectangle_t utillity = shapeArray[i]->getFrameRect();
    double lft_lower_x = utillity.pos.x - utillity.width / 2;
    double lft_lower_y = utillity.pos.y - utillity.height / 2;
    double rht_upper_x = utillity.pos.x + utillity.width / 2;
    double rht_upper_y = utillity.pos.y + utillity.height / 2;
    out << " " << lft_lower_x << " " << lft_lower_y;
    out << " " << rht_upper_x << " " << rht_upper_y;
  }
  out << '\n';

}
