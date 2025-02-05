#include "shapeManip.h"
#include <iostream>
#include <string>
#include "base-types.hpp"

namespace aleksandrov
{
  size_t getShapes(std::istream& input, Shape** shapes, double* params, size_t maxParams, bool& error)
  {
    std::string word;
    size_t count = 0;

    while (input >> word)
    {
      try
      {
        if (word == "SCALE" && count)
        {
          return count;
        }
        else if (word == "SCALE" && !count)
        {
          break;
        }
        size_t paramsCount = getShapeParams(input, params, maxParams);
        if (paramsCount != 3 && paramsCount != 4)
        {
          throw std::logic_error("Incorrect parameters");
        }
        shapes[count] = makeShape(word, params);
      }
      catch (const std::logic_error&)
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

  double getAreaSum(const Shape* const* shapes, size_t count)
  {
    double sum = 0.0;

    for (size_t i = 0; i < count; ++i)
    {
      sum += shapes[i]->getArea();
    }
    return sum;
  }

  Shape* makeShape(const std::string& shapeName, double* params)
  {
    if (shapeName == "RECTANGLE")
    {
      return new Rectangle({params[0], params[1]}, {params[2], params[3]});
    }
    else if (shapeName == "ELLIPSE")
    {
      return new Ellipse({params[0], params[1]}, params[2], params[3]);
    }
    else if (shapeName == "CIRCLE")
    {
      return new Circle({params[0], params[1]}, params[2]);
    }
    return nullptr;
  }

  size_t getShapeParams(std::istream& input, double* params, size_t maxParams)
  {
    size_t paramsCount = 0;
    while (paramsCount != maxParams)
    {
      if (!(input >> params[paramsCount]))
      {
        break;
      }
      ++paramsCount;
    }
    if (paramsCount == maxParams - 1)
    {
      input.clear();
    }
    return paramsCount;
  }

  void scaleShapes(Shape** shapes, size_t count, double x, double y, double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Incorrect coefficient");
    }
    for (size_t i = 0; i < count; ++i)
    {
      rectangle_t frameRect = shapes[i]->getFrameRect();
      double dx = x - frameRect.pos.x;
      double dy = y - frameRect.pos.y;

      shapes[i]->move({x, y});
      shapes[i]->unsafeScale(k);
      shapes[i]->move(-dx * k, -dy * k);
    }
  }

  void printFrameRectCoords(std::ostream& output, const Shape* const* shapes, size_t count)
  {
    rectangle_t frameRect = shapes[0]->getFrameRect();
    printFrameRectPoints(output, frameRect);
    for (size_t i = 1; i < count; ++i)
    {
      rectangle_t frameRect = shapes[i]->getFrameRect();
      output << " ";
      printFrameRectPoints(output, frameRect);
    }
  }

  void printFrameRectPoints(std::ostream& output, const rectangle_t frameRect)
  {
    output << frameRect.pos.x - (frameRect.width / 2);
    output << " " << frameRect.pos.y - (frameRect.height / 2);
    output << " " << frameRect.pos.x + (frameRect.width / 2);
    output << " " << frameRect.pos.y + (frameRect.height / 2);
  }

  void deleteShapes(Shape** shapes)
  {
    size_t i = 0;
    while (shapes[i])
    {
      delete shapes[i];
      ++i;
    }
  }
}

