#include "createCommand.hpp"
#include <stdexcept>
#include <istream>
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"

namespace
{
  duhanina::Rectangle* makeRectangle(std::istream& in)
  {
    double data[4] = {0};
    if (!(in >> data[0] >> data[1] >> data[2] >> data[3]))
    {
      throw std::invalid_argument("Incorrect input");
    }
    return new duhanina::Rectangle({ data[0], data[1] }, { data[2], data[3] });
  }

  duhanina::Circle* makeCircle(std::istream& in)
  {
    double data[3] = {0};
    if (!(in >> data[0] >> data[1] >> data[2]))
    {
      throw std::invalid_argument("Incorrect input");
    }
    return new duhanina::Circle({ data[0], data[1] }, data[2]);
  }

  duhanina::Ellipse* makeEllipse(std::istream& in)
  {
    double data[4] = {0};
    if (!(in >> data[0] >> data[1] >> data[2] >> data[3]))
    {
      throw std::invalid_argument("Incorrect input");
    }
    return new duhanina::Ellipse({ data[0], data[1] }, data[2], data[3]);
  }
}

void duhanina::createShape(std::istream& in, const std::string& shapeType, Shape** shapes, size_t& shapeCount)
{
  if (shapeType == "RECTANGLE")
  {
    Rectangle* rect = makeRectangle(in);
    shapes[shapeCount++] = rect;
  }
  else if (shapeType == "CIRCLE")
  {
    Circle* circ = makeCircle(in);
    shapes[shapeCount++] = circ;
  }
  else if (shapeType == "ELLIPSE")
  {
    Ellipse* ellip = makeEllipse(in);
    shapes[shapeCount++] = ellip;
  }
}

void duhanina::createScale(std::istream& in, size_t shapeCount, double& scalingFactor, point_t& point)
{
  if (shapeCount == 0)
  {
    throw std::logic_error("No shape");
  }
  double x = 0;
  double y = 0;
  if (!(in >> x >> y >> scalingFactor))
  {
    throw std::invalid_argument("Incorrect input");
  }
  point = { x, y };
}

void duhanina::inputShapes(std::istream& in, std::ostream& out, Shape** shapes, size_t& shapeCount)
{
  std::string shapeType;
  while (in >> shapeType && shapeType != "SCALE")
  {
    try
    {
      createShape(in, shapeType, shapes, shapeCount);
    }
    catch (const std::invalid_argument& e)
    {
      out << e.what() << "\n";
    }
  }
  if (in.eof())
  {
    throw std::logic_error("No scale");
  }
}
