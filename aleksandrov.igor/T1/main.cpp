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
  std::string str;
  size_t count = 0;
  try
  {
    double sumBefore = 0;
    std::string scaleDescription;
    while (!std::cin.eof())
    {
      str = aleksandrov::getString(std::cin);
      aleksandrov::Shape* shape = aleksandrov::makeShape(str, wasDescriptionError);
      if (!shape)
      {
        if (aleksandrov::getWord(str, 1) == "SCALE")
        {
          scaleDescription = str;
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
      return 1;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << sumBefore << " ";
    for (size_t i = 0; i < count; ++i)
    {
      aleksandrov::rectangle_t frameRect = shapes[i]->getFrameRect();
      std::cout << frameRect.pos_.x_ - (frameRect.width_ / 2) << " ";
      std::cout << frameRect.pos_.y_ - (frameRect.height_ / 2) << " ";
      std::cout << frameRect.pos_.x_ + (frameRect.width_ / 2) << " ";
      std::cout << frameRect.pos_.y_ + (frameRect.height_ / 2);
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
      std::cout << frameRect.pos_.x_ - (frameRect.width_ / 2) << " ";
      std::cout << frameRect.pos_.y_ - (frameRect.height_ / 2) << " ";
      std::cout << frameRect.pos_.x_ + (frameRect.width_ / 2) << " ";
      std::cout << frameRect.pos_.y_ + (frameRect.height_ / 2);
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
    return 1;
  }
  if (wasDescriptionError)
  {
    std::cerr << "WARNING: Some supporting shapes had a description problems!\n";
  }
  for (size_t i = 0; i < count; ++i)
  {
    if (!shapes[i])
    {
      continue;
    }
    delete shapes[i];
  }
}

