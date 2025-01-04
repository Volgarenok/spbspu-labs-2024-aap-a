#include "createCommand.hpp"
#include <stdexcept>
#include "makeShape.hpp"
#include "destroy.hpp"

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
    catch (const std::exception& e)
    {
      out << e.what() << "\n";
      destroy(shapes, shapeCount);
    }
  }
  if (in.eof())
  {
    out << "No scale\n";
  }
}
