#include <iostream>
#include <memory>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "shape.hpp"
#include "rectangle.hpp"
#include "rectanglepoints.hpp"
#include "dynamicinput.h"
#include "ellipse.hpp"
#include "diamond.hpp"


int main()
{
  averenkov::Shape* shapes[10000];
  size_t shapeCount = 0;
  bool hasErrors = false;
  char* input;
  averenkov::point_t scale_center;
  double factor;
  while (shapeCount < 10000)
  {
    input = averenkov::stringInput(std::cin);
    if (input == nullptr || !std::cin)
    {
      break;
    }
    std::istringstream line(input);
    std::string command;
    line >> command;

    try
    {
      if (command.empty())
      {
        free(input);
        continue;
      }
      else if (command == "RECTANGLE")
      {
        averenkov::point_t a, c;
        if (!(line >> a.x >> a.y >> c.x >> c.y) || a.x > c.x || a.y > c.x)
        {
          throw std::invalid_argument("Invalid RECTANGLE");
        }
        shapes[shapeCount++] = new averenkov::Rectangle(a, c);
      }
      else if (command == "ELLIPSE")
      {
        averenkov::point_t center;
        double a, b;
        if (!(line >> center.x >> center.y >> a >> b) || a <= 0 || b <= 0)
        {
          throw std::invalid_argument("Invalid ELLIPSE");
        }
        shapes[shapeCount++] = new averenkov::Ellipse(center, a, b);
      }
      else if (command == "DIAMOND")
      {
        averenkov::point_t a;
        averenkov::point_t b;
        averenkov::point_t c;
        if (!(line >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y))
        {
          throw std::invalid_argument("Invalid DIAMOND");
        }
        if ((a.x == b.x && b.x == c.x) || (a.y == b.y && b.y == c.y))
        {
          throw std::invalid_argument("Invalid DIAMOND");
        }
        if ((a.x != b.x && a.x != c.x && b.x != c.x) || (a.y != b.y && a.y != c.y && b.y != c.y))
        {
          throw std::invalid_argument("Invalid DIAMOND");
        }
        else
        {
          shapes[shapeCount++] = new averenkov::Diamond(a, b, c);
        }
      }
      else if (command == "SCALE")
      {
        if (shapeCount == 0)
        {
          std::cerr << "Nothing to scale\n";
          free(input);
          return 1;
        }
        if (!(line >> scale_center.x >> scale_center.y >> factor) || factor <= 0)
        {
          for(size_t i = 0; i < shapeCount; ++i)
          {
            delete shapes[i];
          }
          std::cerr << "Invalid scale\n";
          free(input);
          return 1;
        }
        free(input);
        break;
      }
    }
    catch (const std::invalid_argument&)
    {
      hasErrors = true;
    }
    free(input);
  }

  if (std::cin.eof())
  {
    std::cerr << "No scale\n";
    free(input);
    for(size_t i = 0; i < shapeCount; ++i)
    {
      delete shapes[i];
    }
    return 1;
  }

  double sum = 0;
  std::cout << std::fixed << std::setprecision(1);

  for (size_t i = 0; i < shapeCount; ++i)
  {
    sum += shapes[i]->getArea();
  }

  std::cout << sum;

  for (size_t i = 0; i < shapeCount; ++i)
  {
    std::cout << " " << averenkov::getLeftBot(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getLeftBot(shapes[i]->getFrameRect()).y << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).y;
    shapes[i]->scale(factor);
    averenkov::shapeScale(shapes[i], scale_center, factor);
    sum += shapes[i]->getArea();
  }

  std::cout << "\n";
  sum = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    sum += shapes[i]->getArea();
  }
  std::cout << sum;

  for (size_t i = 0; i < shapeCount; ++i)
  {
    std::cout << " " << averenkov::getLeftBot(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getLeftBot(shapes[i]->getFrameRect()).y << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).y;
    delete shapes[i];
  }

  std::cout << "\n";

  if (hasErrors)
  {
    std::cerr << "Errors descriptions\n";
  }

  return 0;
}
