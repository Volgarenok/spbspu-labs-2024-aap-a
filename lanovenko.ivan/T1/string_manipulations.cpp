#include "string_manipulations.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

lanovenko::Shape* lanovenko::parseShape(const char* str)
{
  if (std::strstr(str, "RECTANGLE"))
  {
    Shape* Rectangle = parseRectangle(str);
    return Rectangle;
  }
  if (std::strstr(str, "DIAMOND"))
  {
    Shape* Diamond = parseDiamond(str);
    return Diamond;
  }
  if (std::strstr(str, "TRIANGLE"))
  {
    Shape* Triangle = parseTriangle(str);
    return Triangle;
  }
  if (std::strstr(str, "PARALLELOGRAM"))
  {
    Shape* Parallelogram = parseParallelogram(str);
    return Parallelogram;
  }
  else
  {
    throw std::logic_error("Wrond name of figure");
  }
}

lanovenko::Shape* lanovenko::parseRectangle(const char* str)
{
  size_t nameLength = lanovenko::getNameLength(str);
  const char* coordsStr = str + nameLength;
  double coords[4]{};
  size_t parseCount = split(coordsStr);
  if (parseCount != 4)
  {
    throw std::logic_error("Wrong coords capacity");
  }
  getCoords(coords, coordsStr, parseCount);
  point_t leftLower = { coords[0], coords[1] };
  point_t rigthUpper = { coords[2], coords[3] };
  return new Rectangle{ leftLower, rigthUpper };
}

lanovenko::Shape* lanovenko::parseDiamond(const char* str)
{
  size_t nameLength = lanovenko::getNameLength(str);
  const char* coordsStr = str + nameLength;
  double coords[6]{};
  size_t parseCount = split(coordsStr);
  parseCount = split(coordsStr);
  if (parseCount != 6)
  {
    throw std::logic_error("Wrong coords capacity");
  }
  getCoords(coords,coordsStr, parseCount);
  point_t p1 = { coords[0], coords[1] };
  point_t p2 = { coords[2], coords[3] };
  point_t p3 = { coords[4], coords[5] };
  return new Diamond{ p1, p2, p3 };
}

lanovenko::Shape* lanovenko::parseTriangle(const char* str)
{
  size_t nameLength = lanovenko::getNameLength(str);
  const char* coordsStr = str + nameLength;
  double coords[6]{};
  size_t parseCount = split(coordsStr);
  parseCount = split(coordsStr);
  if (parseCount != 6)
  {
    throw std::logic_error("Wrong coords capacity");
  }
  getCoords(coords, coordsStr, parseCount);
  point_t p1 = { coords[0], coords[1] };
  point_t p2 = { coords[2], coords[3] };
  point_t p3 = { coords[4], coords[5] };
  return new Triangle{ p1, p2, p3 };
}

lanovenko::Shape* lanovenko::parseParallelogram(const char* str)
{
  size_t nameLength = lanovenko::getNameLength(str);
  const char* coordsStr = str + nameLength;
  double coords[6]{};
  size_t parseCount = split(coordsStr);
  parseCount = split(coordsStr);
  if (parseCount != 6)
  {
    throw std::logic_error("Wrong coords capacity");
  }
  getCoords(coords, coordsStr, parseCount);
  point_t p1 = { coords[0], coords[1] };
  point_t p2 = { coords[2], coords[3] };
  point_t p3 = { coords[4], coords[5] };
  return new Parallelogram{ p1, p2, p3 };
}

std::size_t lanovenko::split(const char* str)
{
  std::size_t res = 0;
  for (size_t i = 0; i < strlen(str); i++)
  {
    std::string b = " ";
    while (str[i] != ' ' && i < strlen(str))
    {
      i++;
    }
    res++;
  }
  return res;
}

size_t lanovenko::getNameLength(const char* str)
{
  size_t res = 0;
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (std::isalpha(str[i]))
    {
      res++;
    }
  }
  return res + 1;
}

void lanovenko::getCoords(double* array, const char* str, size_t capacityCoords)
{
  const char* currentPos = str;
  char* endPos = nullptr;
  for (size_t i = 0; i < capacityCoords; i++)
  {
    double value = std::strtod(currentPos, &endPos);
    array[i] = value;
    currentPos = endPos;
  }
}

void lanovenko::parseScale(double* arr, const char* str)
{
  size_t nameLength = lanovenko::getNameLength(str);
  const char* coordsStr = str + nameLength;
  std::size_t parseCount = 0;
  parseCount = split(coordsStr);
  if (parseCount != 3)
  {
    throw std::invalid_argument("Wrong coord count");
  }
  getCoords(arr, coordsStr, parseCount);
}
