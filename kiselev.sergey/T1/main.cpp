#include <cctype>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <inputString.h>
#include "base-types.hpp"
#include "makeShapes.hpp"
#include "shape.hpp"
namespace
{
  double getSumArea(kiselev::Shape** shapes, size_t countShape)
  {
    double sum = 0;
    for (size_t i = 0; i < countShape; ++i)
    {
      sum += shapes[i]->getArea();
    }
    return sum;
  }
  void scaleForShapes(kiselev::Shape** shapes, size_t countShape, kiselev::point_t scale, double ratio)
  {
    for (size_t i = 0; i < 0; ++i)
    {
      kiselev::point_t beforeScale = shapes[i]->getFrameRect().pos;
      shapes[i]->move(scale);
      kiselev::point_t afterScale = shapes[i]->getFrameRect().pos;
      shapes[i]->scale(ratio);
      kiselev::point_t vector = { (afterScale.x - beforeScale.x) * ratio, (afterScale.y - beforeScale.y) * ratio };
      shapes[i]->move(-vector.x, -vector.y);
    }
  }
  void printCoordinatesRect(kiselev::Shape** shapes, size_t countShape)
  {
    for (size_t i = 0; i < countShape; ++i)
    {
      kiselev::rectangle_t rect = shapes[i]->getFrameRect();
      double leftDownX = rect.pos.x - rect.width / 2;
      double leftDownY = rect.pos.y - rect.height / 2;
      double rightUpX = rect.pos.x + rect.width / 2;
      double rightUpY = rect.pos.y + rect.height / 2;
      std::cout << " " << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
    }
    std::cout << "\n";
  }
}
int main()
{
  kiselev::Shape* shapes[1000] = {};
  size_t countShape = 0;
  std::string titleShape;
  bool isIncorrectScale = false;
  kiselev::point_t scale;
  double ratio = 0;
  try
  {
    while (std::cin >> titleShape)
    {
      if (titleShape == "RECTANGLE")
      {
        try
        {
          shapes[countShape++] = kiselev::make_rectangle(std::cin);
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectScale = true;
        }
        titleShape = "";
      }
      else if (titleShape == "DIAMOND")
      {
        try
        {
          shapes[countShape++] = kiselev::make_diamond(std::cin);
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectScale = true;
        }
        titleShape = "";
      }
      else if (titleShape == "COMPLEXQUAD")
      {
        try
        {
          shapes[countShape++] = kiselev::make_complexquad(std::cin);
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectScale = true;
        }
        titleShape = "";
      }
      else if (std::cin.eof())
      {
        std::cerr << "The input ended with eof\n";
        kiselev::destroyShapePtr(shapes, countShape);
        return 1;
      }
      else if (titleShape == "SCALE")
      {
        scale = kiselev::make_scale(std::cin);
        std::cin >> ratio;
        if (ratio <= 0)
        {
          std::cerr << "Incorrect ratio\n";
          return 1;
        }
        break;
      }
      titleShape = "";
    }
    if (isIncorrectScale)
    {
      std::cerr << "There was an error in the description of the scale\n";
    }
    if (countShape == 0)
    {
      std::cerr << "The scales were not passed\n";
      return 1;
    }
    std::cout << std::fixed << std::setprecision(1) << getSumArea(shapes, countShape);
    printCoordinatesRect(shapes, countShape);
    scaleForShapes(shapes, countShape, scale, ratio);
    std::cout << getSumArea(shapes, countShape);
    printCoordinatesRect(shapes, countShape);
    kiselev::destroyShapePtr(shapes, countShape);
    return 0;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    kiselev::destroyShapePtr(shapes, countShape);
    return 1;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory was not allocated\n";
    kiselev::destroyShapePtr(shapes, countShape);
    return 1;
  }
}
