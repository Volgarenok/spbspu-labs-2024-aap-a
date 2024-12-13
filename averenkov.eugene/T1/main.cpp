#include "shape.hpp"
#include "rectangle.hpp"
#include "rectanglepoints.hpp"
#include "dynamicinput.h"
#include "ellipse.hpp"
#include "diamond.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

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
    if (command.empty())
    {
      free(input);
      continue;
    }

    try
    {
      if (command == "RECTANGLE")
      {
        averenkov::point_t a, c;
        if (!(line >> a.x >> a.y >> c.x >> c.y))
        {
          throw std::invalid_argument("Invalid RECTANGLE");
        }
        shapes[shapeCount++] = new averenkov::Rectangle(a, c);
      }
      else if (command == "ELLIPSE")
      {
        averenkov::point_t center;
        double a, b;
        if (!(line >> center.x >> center.y >> a >> b))
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
        else
        {
          shapes[shapeCount++] = new averenkov::Diamond(a, b, c);
        }
      }
      else if (command == "SCALE")
      {
        if (!(line >> scale_center.x >> scale_center.y >> factor) || factor <= 0)
        {
          std::cerr << "Invalid scale\n";
          return 1;
        }
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
    return 1;
  }

  if (hasErrors)
  {
    std::cerr << "Errors descriptions\n";
  }

  for (size_t i = 0; i < shapeCount; ++i)
  {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << shapes[i]->getArea() << " ";
    std::cout << averenkov::getLeftBot(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getLeftBot(shapes[i]->getFrameRect()).y << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).y << " \n";
    shapes[i]->scale(scale_center, factor);
    std::cout << shapes[i]->getArea() << " ";
    std::cout << averenkov::getLeftBot(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getLeftBot(shapes[i]->getFrameRect()).y << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).x << " ";
    std::cout << averenkov::getRightTop(shapes[i]->getFrameRect()).y << " \n";
    delete shapes[i];
  }
  return 0;
}
