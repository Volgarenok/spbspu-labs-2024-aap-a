#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include <getString.h>
#include <string>

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

int main()
{
  constexpr const size_t maxShapes = 10000;
  Shape* shapes[maxShapes];
  std::string inputStr;
  char* str = nullptr;
  try
  {
    size_t count = 0;
    while ((str = aleksandrov::getString(std::cin)) && !std::cin.eof())
    {
      inputStr = str;
      delete[] str;
      Shape* shape = makeShape(inputStr);
      if (!shape)
      {
        continue;
      }
      shapes[count++] = shape;
    }
    for (size_t i = 0; i < count; ++i)
    {
      std::cout << shapes[i]->getArea() << "\n";
      delete shapes[i];
    }
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

