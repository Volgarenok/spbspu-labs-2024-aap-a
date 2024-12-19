#include "shapeManip.h"
#include "stringManip.h"
#include "base-types.hpp"
#include <iostream>

namespace aleksandrov
{
  Rectangle* makeRectangle(const std::string rectangleParams, bool& error)
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

  Ellipse* makeEllipse(const std::string ellipseParams, bool& error)
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

  Circle* makeCircle(const std::string circleParams, bool& error)
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

  Shape* makeShape(const std::string shapeDescription, bool& error)
  {
    std::string shapeName = getWord(shapeDescription, 1);
    size_t paramsCount = 0;
    std::string params = getShapeParams(shapeDescription, paramsCount);

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

  void doScale(Shape** shapes, size_t count, double& x, double& y, double& k, double& sum)
  {
    for (size_t i = 0; i < count; ++i)
    {
      Shape* shape = shapes[i];
      rectangle_t frameRect = shape->getFrameRect();
      double xCenter = frameRect.pos.x;
      double yCenter = frameRect.pos.y;
      double dx = x - xCenter;
      double dy = y - yCenter;
      shape->move({x, y});
      shape->scale(k);
      shape->move(-dx * k, -dy * k);
      sum += shape->getArea();
    }
  }

  void printFrameRectCoords(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i)
    {
      aleksandrov::rectangle_t frameRect = shapes[i]->getFrameRect();
      std::cout << frameRect.pos.x - (frameRect.width / 2) << " ";
      std::cout << frameRect.pos.y - (frameRect.height / 2) << " ";
      std::cout << frameRect.pos.x + (frameRect.width / 2) << " ";
      std::cout << frameRect.pos.y + (frameRect.height / 2);
      if (i < count - 1)
      {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }

  void deleteShapes(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i)
    {
      delete shapes[i];
    }
  }
}
