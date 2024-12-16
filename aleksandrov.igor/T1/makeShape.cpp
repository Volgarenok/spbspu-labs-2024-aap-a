#include "makeShape.h"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include "getWord.h"

aleksandrov::Rectangle* aleksandrov::makeRectangle(const std::string rectangleParams, bool& error)
{
  point_t a;
  a.x = std::stod(getWord(rectangleParams, 1));
  a.y = std::stod(getWord(rectangleParams, 2));
  point_t b;
  b.x = std::stod(getWord(rectangleParams, 3));
  b.y = std::stod(getWord(rectangleParams, 4));
  if (a.x >= b.x || a.y >= b.y)
  {
    error = 1;
    return nullptr;
  }
  return new Rectangle(a, b);
}

aleksandrov::Ellipse* aleksandrov::makeEllipse(const std::string ellipseParams, bool& error)
{
  point_t center;
  center.x = std::stod(getWord(ellipseParams, 1));
  center.y = std::stod(getWord(ellipseParams, 2));
  double vr = std::stod(getWord(ellipseParams, 3));
  double hr = std::stod(getWord(ellipseParams, 4));
  if (vr <= 0 || hr <= 0)
  {
    error = 1;
    return nullptr;
  }
  return new Ellipse(center, vr, hr);
}

aleksandrov::Circle* aleksandrov::makeCircle(const std::string circleParams, bool& error)
{
  point_t center;
  center.x = std::stod(getWord(circleParams, 1));
  center.y = std::stod(getWord(circleParams, 2));
  double r = std::stod(getWord(circleParams, 3));
  if (r <= 0)
  {
    error = 1;
    return nullptr;
  }
  return new Circle(center, r);
}

aleksandrov::Shape* aleksandrov::makeShape(const std::string shapeDescription, bool& error)
{
  std::string shapeName = getWord(shapeDescription, 1);

  std::string params, param;
  size_t paramsCount = 0;
  param = getWord(shapeDescription, paramsCount + 2);
  while (param != "")
  {
    if (paramsCount == 0)
    {
      params += param;
    }
    else
    {
      params += " " + param;
    }
    ++paramsCount;
    param = getWord(shapeDescription, paramsCount + 2);
  }

  if (shapeName == "RECTANGLE")
  {
    if (paramsCount != 4)
    {
      error = 1;
      return nullptr;
    }
    return makeRectangle(params, error);
  }
  else if (shapeName == "ELLIPSE")
  {
    if (paramsCount != 4)
    {
      error = 1;
      return nullptr;
    }
    return makeEllipse(params, error);
  }
  else if (shapeName == "CIRCLE")
  {
    if (paramsCount != 3)
    {
      error = 1;
      return nullptr;
    }
    return makeCircle(params, error);
  }
  return nullptr;
}
