#include "createCommand.hpp"
#include <stdexcept>
#include <istream>
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"

namespace
{
  void readArray(std::istream& in, double* data, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      if (!(in >> data[i]))
      {
        throw std::invalid_argument("Incorrect input");
      }
    }
  }

  duhanina::Rectangle* makeRectangle(std::istream& in)
  {
    double data[4] = {0};
    readArray(in, data, 4);
    return new duhanina::Rectangle({ data[0], data[1] }, { data[2], data[3] });
  }

  duhanina::Circle* makeCircle(std::istream& in)
  {
    double data[3] = {0};
    readArray(in, data, 3);
    return new duhanina::Circle({ data[0], data[1] }, data[2]);
  }

  duhanina::Ellipse* makeEllipse(std::istream& in)
  {
    double data[4] = {0};
    readArray(in, data, 4);
    return new duhanina::Ellipse({ data[0], data[1] }, data[2], data[3]);
  }

  void createShape(std::istream& in, const std::string& shapeType, duhanina::Shape** shapes, size_t& shapeCount)
  {
    if (shapeType == "RECTANGLE")
    {
      duhanina::Rectangle* rect = makeRectangle(in);
      shapes[shapeCount++] = rect;
    }
    else if (shapeType == "CIRCLE")
    {
      duhanina::Circle* circ = makeCircle(in);
      shapes[shapeCount++] = circ;
    }
    else if (shapeType == "ELLIPSE")
    {
      duhanina::Ellipse* ellip = makeEllipse(in);
      shapes[shapeCount++] = ellip;
    }
  }
}

void duhanina::createScale(std::istream& in, double& scalingFactor, point_t& point)
{
  double x = 0;
  double y = 0;
  if (!(in >> x >> y >> scalingFactor))
  {
    throw std::invalid_argument("Incorrect input");
  }
  point = { x, y };
}

void duhanina::inputShapes(std::istream& in, Shape** shapes, size_t& shapeCount, bool& errorArg)
{
  std::string shapeType;
  while (in >> shapeType && shapeType != "SCALE")
  {
    try
    {
      createShape(in, shapeType, shapes, shapeCount);
    }
    catch (const std::invalid_argument&)
    {
      errorArg = true;
    }
  }
  if (in.eof())
  {
    throw std::logic_error("No scale");
  }
}
