#include "make_shapes.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "square.hpp"

void komarova::makeShapes(std::istream& input, Shape** shapes, bool& wrong_shape, size_t& count, double& x_sc, double& y_sc, double& coef)
{
  std::string figure;
  while (input >> figure && figure != "SCALE")
  {
    try
    {
      if (figure == "RECTANGLE")
      {
        double x1, y1, x2, y2;
        input >> x1 >> y1 >> x2 >> y2;
        point_t a{ x1, y1 };
        point_t b{ x2, y2 };
        shapes[count] = new Rectangle(a, b);
        count++;
      }
      else if (figure == "CIRCLE")
      {
        double x, y, radius;
        input >> x >> y >> radius;
        point_t point_c{ x, y };
        shapes[count] = new Circle(point_c, radius);
        count++;
      }
      else if (figure == "TRIANGLE")
      {
        double x1, y1, x2, y2, x3, y3;
        input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        point_t a{ x1, y1 };
        point_t b{ x2, y2 };
        point_t c{ x3, y3 };
        shapes[count] = new Triangle(a, b, c);
        count++;
      }
      else if (figure == "SQUARE")
      {
        double x, y, len;
        input >> x >> y >> len;
        point_t low_left{ x, y };
        shapes[count] = new Square(low_left, len);
        count++;
      }
    }
    catch (const std::logic_error& e)
    {
      wrong_shape = true;
    }
  }
  if (input.eof() && figure != "SCALE")
  {
    throw std::logic_error("SCALE Error");
  }
  input >> x_sc >> y_sc >> coef;
}
void komarova::sumArea(std::ostream& output, Shape** shapes)
{
  double sum = 0.0;
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    sum += shapes[i]->getArea();
  }
  output << sum;
}
void komarova::getFramerectXY(std::ostream& output, Shape** shapes)
{
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    rectangle_t frame_rect = shapes[i]->getFrameRect();
    output << " " << frame_rect.pos.x - (frame_rect.width / 2.0);
    output << " " << frame_rect.pos.y - (frame_rect.height / 2.0);
    output << " " << frame_rect.pos.x + (frame_rect.width / 2.0);
    output << " " << frame_rect.pos.y + (frame_rect.height / 2.0);
  }
}
void komarova::scale(Shape** shapes, point_t point, double coef)
{
  if (coef <= 0.0)
  {
    throw std::logic_error("incorrect coefficient");
  }
  scaleUnsafe(shapes, point, coef);
}
void komarova::scaleUnsafe(Shape** shapes, point_t point, double coef)
{
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    point_t p = shapes[i]->getFrameRect().pos;
    shapes[i]->move(point);
    point_t new_p = shapes[i]->getFrameRect().pos;
    point_t vector = {(new_p.x - p.x) * coef, (new_p.y - p.y) * coef};
    shapes[i]->scaleUnsafe(coef);
    shapes[i]->move(-vector.x, -vector.y);
  }
}
void komarova::deleteShapes(Shape** shapes)
{
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    delete shapes[i];
  }
}
