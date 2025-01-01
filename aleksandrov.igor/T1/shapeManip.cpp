#include "shapeManip.h"
#include <iostream>
#include <string>
#include <limits>
#include "base-types.hpp"

namespace aleksandrov
{
  size_t getShapes(std::istream& input, Shape** shapes, bool& error)
  {
    std::string word;
    size_t count = 0;

    while (input >> word)
    {
      try
      {
        if (word == "RECTANGLE")
        {
          shapes[count] = makeRectangle(input);
        }
        else if (word == "ELLIPSE")
        {
          shapes[count] = makeEllipse(input);
        }
        else if (word == "CIRCLE")
        {
          shapes[count] = makeCircle(input);
        }
        else if (word == "SCALE" && count)
        {
          return count;
        }
        else if (word == "SCALE" && !count)
        {
          break;
        }
      }
      catch (const std::logic_error& e)
      {
        error = true;
        input.clear();
        continue;
      }
      if (shapes[count])
      {
        ++count;
      }
    }
    if (word == "SCALE" && !count)
    {
      throw std::logic_error("There were no shapes to scale!");
    }
    if (count)
    {
      throw std::logic_error("There was no SCALE command description!");
    }
    throw std::logic_error("Incorrect input!");
  }

  double getAreaSum(Shape** shapes, size_t count)
  {
    double sum = 0.0;

    for (size_t i = 0; i < count; ++i)
    {
      sum += shapes[i]->getArea();
    }
    return sum;
  }

  Rectangle* makeRectangle(std::istream& input)
  {
    point_t a;
    point_t b;
    if (!(input >> a.x >> a.y >> b.x >> b.y))
    {
      throw std::logic_error("Incorrect input!");
    }
    return new Rectangle(a, b);
  }

  Ellipse* makeEllipse(std::istream& input)
  {
    point_t center;
    double vr = 0.0;
    double hr = 0.0;
    if (!(input >> center.x >> center.y >> vr >> hr))
    {
      throw std::logic_error("Incorrect input!");
    }
    return new Ellipse(center, vr, hr);
  }

  Circle* makeCircle(std::istream& input)
  {
    point_t center;
    double r = 0.0;
    if (!(input >> center.x >> center.y >> r))
    {
      throw std::logic_error("Incorrect input!");
    }
    return new Circle(center, r);
  }

  void getScaleParams(std::istream& input, double& x, double& y, double& k)
  {
    if (!(input >> x >> y >> k))
    {
      throw std::logic_error("Incorrect input!");
    }
  }

  void scaleShapes(Shape** shapes, size_t count, double x, double y, double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Incorrect coefficient!");
    }
    for (size_t i = 0; i < count; ++i)
    {
      rectangle_t frameRect = shapes[i]->getFrameRect();
      double dx = x - frameRect.pos.x;
      double dy = y - frameRect.pos.y;

      shapes[i]->move({x, y});
      shapes[i]->scale(k);
      shapes[i]->move(-dx * k, -dy * k);
    }
  }

  void printFrameRectCoords(std::ostream& output, Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i)
    {
      rectangle_t frameRect = shapes[i]->getFrameRect();

      output << frameRect.pos.x - (frameRect.width / 2) << " ";
      output << frameRect.pos.y - (frameRect.height / 2) << " ";
      output << frameRect.pos.x + (frameRect.width / 2) << " ";
      output << frameRect.pos.y + (frameRect.height / 2);
      if (i < count - 1)
      {
        output << " ";
      }
    }
  }

  void deleteShapes(Shape** shapes)
  {
    size_t i = 0;
    while (shapes[i])
    {
      delete shapes[i++];
    }
  }
}

