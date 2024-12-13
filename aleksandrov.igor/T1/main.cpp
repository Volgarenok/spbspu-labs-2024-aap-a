#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include <getString.h>
#include <string>
#include <iomanip>

bool wasDescriptionError = 0;

std::string getWord(const std::string str, size_t numberOfWord)
{
  size_t strSize = str.size();
  size_t wordStart = 0;
  size_t wordIndex = 0;
  for (size_t i = 0; i <= strSize; ++i)
  {
    if (str[i] == ' ' || i == strSize)
    {
      if (wordStart < i)
      {
        if (wordIndex == numberOfWord - 1)
        {
          return str.substr(wordStart, i - wordStart);
        }
        ++wordIndex;
      }
      wordStart = i + 1;
    }
  }
  return "";
}

Rectangle* makeRectangle(const std::string rectangleParams)
{
  point_t a;
  a.x_ = std::stod(getWord(rectangleParams, 1));
  a.y_ = std::stod(getWord(rectangleParams, 2));
  point_t b;
  b.x_ = std::stod(getWord(rectangleParams, 3));
  b.y_ = std::stod(getWord(rectangleParams, 4));
  return new Rectangle(a, b);
}

Shape* makeShape(const std::string shapeDescription)
{
  std::string shapeName = getWord(shapeDescription, 1);
  std::string shapeParams;
  std::string param;
  size_t paramsCount = 0;
  param = getWord(shapeDescription, paramsCount + 2);
  while (param != "")
  {
    if (paramsCount == 0)
    {
      shapeParams += param;
    }
    else
    {
      shapeParams += " " + param;
    }
    ++paramsCount;
    param = getWord(shapeDescription, paramsCount + 2);
  }
  if (shapeName == "RECTANGLE")
  {
    if (paramsCount != 4)
    {
      wasDescriptionError = 1;
      return nullptr;
    }
    return makeRectangle(shapeParams);
  }
  return nullptr;
}

Shape* doScale(const std::string scaleDescription, Shape* shape)
{
  std::string scaleParams;
  std::string param;
  size_t paramsCount = 0;
  param = getWord(scaleDescription, paramsCount + 2);
  while (param != "")
  {
    if (paramsCount == 0)
    {
      scaleParams += param;
    }
    else
    {
      scaleParams += " " + param;
    }
    ++paramsCount;
    param = getWord(scaleDescription, paramsCount + 2);
  }
  point_t scalePoint;
  scalePoint.x_ = std::stod(getWord(scaleParams, 1));
  scalePoint.y_ = std::stod(getWord(scaleParams, 2));
  size_t k = std::stod(getWord(scaleParams, 3));
  if (paramsCount != 3 || k <= 0.0)
  {
    return nullptr;
  }
  point_t tempPoint = (shape->getFrameRect()).pos_;
  double dx = scalePoint.x_ - tempPoint.x_;
  double dy = scalePoint.y_ - tempPoint.y_;
  shape->move(scalePoint);
  shape->scale(k);
  dx /= k;
  dy /= k;
  shape->move(dx, dy);
  return shape;
}

int main()
{
  constexpr const size_t maxShapes = 10000;
  Shape* shapes[maxShapes];
  std::string inputStr;
  char* str = nullptr;
  try
  {
    double sumBefore = 0;
    size_t count = 0;
    std::string scaleDescription;
    while ((str = aleksandrov::getString(std::cin)) && !std::cin.eof())
    {
      inputStr = str;
      delete[] str;
      Shape* shape = makeShape(inputStr);
      if (!shape)
      {
        if (getWord(inputStr, 1) == "SCALE")
        {
          scaleDescription = inputStr;
          break;
        }
        continue;
      }
      shapes[count++] = shape;
      rectangle_t shapeFrameRect = shape->getFrameRect();
      sumBefore += (shapeFrameRect.width_ * shapeFrameRect.height_);
    }
    std::cout << sumBefore << " ";
    for (size_t i = 0; i < count; ++i)
    {
      rectangle_t frameRect = shapes[i]->getFrameRect();
      std::cout << std::setprecision(3) << frameRect.pos_.x_ - (frameRect.width_ / 2) << " ";
      std::cout << std::setprecision(3) << frameRect.pos_.y_ - (frameRect.height_ / 2) << " ";
      std::cout << std::setprecision(3) << frameRect.pos_.x_ + (frameRect.width_ / 2) << " ";
      std::cout << std::setprecision(3) << frameRect.pos_.y_ + (frameRect.height_ / 2);
      if (i < count - 1)
      {
        std::cout << " ";
      }
    }
    std::cout << "\n";
    double sumAfter = 0;
    for (size_t i = 0; i < count; ++i)
    {
      doScale(scaleDescription, shapes[i]);
      rectangle_t shapeFrameRect = shapes[i]->getFrameRect();
      sumAfter += (shapeFrameRect.width_ * shapeFrameRect.height_);
    }
    std::cout << sumAfter << " ";
    for (size_t i = 0; i < count; ++i)
    {
      rectangle_t frameRect = shapes[i]->getFrameRect();
      std::cout << std::setprecision(3) << frameRect.pos_.x_ - (frameRect.width_ / 2) << " ";
      std::cout << std::setprecision(3) << frameRect.pos_.y_ - (frameRect.height_ / 2) << " ";
      std::cout << std::setprecision(3) << frameRect.pos_.x_ + (frameRect.width_ / 2) << " ";
      std::cout << std::setprecision(3) << frameRect.pos_.y_ + (frameRect.height_ / 2);
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
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    return 1;
  }
  if (wasDescriptionError)
  {
    std::cout << "WARNING: Some supporting shapes had a description problems!\n";
  }
}

