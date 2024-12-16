#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include "base-types.hpp"
#include <getString.h>
#include <string>
#include <iomanip>
#include "makeShape.h"
#include "getWord.h"
#include "doScale.h"

int main()
{
  bool wasDescriptionError = 0;
  constexpr const size_t maxShapes = 10000;
  aleksandrov::Shape* shapes[maxShapes];
  std::string inputStr;
  char* str = nullptr;
  size_t count = 0;
  try
  {
    double sumBefore = 0;
    std::string scaleDescription;
    while ((str = aleksandrov::getString(std::cin)) && !std::cin.eof())
    {
      inputStr = str;
      delete[] str;
      aleksandrov::Shape* shape = aleksandrov::makeShape(inputStr, wasDescriptionError);
      if (!shape)
      {
        if (aleksandrov::getWord(inputStr, 1) == "SCALE")
        {
          scaleDescription = inputStr;
          break;
        }
        continue;
      }
      shapes[count++] = shape;
      sumBefore += shape->getArea();
    }
    std::string coeff = aleksandrov::getWord(scaleDescription, 4);
    if (coeff == "" || std::stod(coeff) <= 0 || count == 0)
    {
      std::cerr << "ERROR: Incorrect SCALE command description!\n";
      for (size_t i = 0; i < count; ++i)
      {
        delete shapes[i];
      }
      return 1;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << sumBefore << " ";
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
    double sumAfter = 0;
    for (size_t i = 0; i < count; ++i)
    {
      aleksandrov::doScale(scaleDescription, shapes[i]);
      sumAfter += shapes[i]->getArea();
    }
    std::cout << sumAfter << " ";
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
  catch (const std::bad_alloc& e)
  {
    std::cerr << "ERROR: Out of memory!\n";
    for (size_t i = 0; i < count; ++i)
    {
      delete shapes[i];
    }
    return 1;
  }
  if (wasDescriptionError)
  {
    std::cerr << "WARNING: Some supporting shapes had a description problems!\n";
  }
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}

