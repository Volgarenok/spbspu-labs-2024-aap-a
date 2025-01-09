#include "shapeManip.h"
#include <iostream>
#include <string>
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
        size_t paramsCount = 0;
        if (!(paramsCount = getParamsCount(word)))
        {
          throw std::logic_error("Incorrect input!");
        }
        if (word == "SCALE" && count)
        {
          return count;
        }
        else if (word == "SCALE" && !count)
        {
          break;
        }
        double* params = new double[paramsCount];
        if (!getShapeParams(input, params, paramsCount))
        {
          delete[] params;
          throw std::logic_error("Incorrect parameters!");
        }
        shapes[count] = makeShape(word, params);
        delete[] params;
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

  size_t getParamsCount(const std::string& command)
  {
    if (command == "RECTANGLE" || command == "ELLIPSE")
    {
      return 4;
    }
    else if (command == "CIRCLE" || command == "SCALE")
    {
      return 3;
    }
    return 0;
  }

  std::istream& getShapeParams(std::istream& input, double* params, size_t paramsCount)
  {
    for (size_t i = 0; i < paramsCount; ++i)
    {
      input >> params[i];
    }
    return input;
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
      delete shapes[i];
      ++i;
    }
  }
}

