#include "string_manipulations.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

lanovenko::Shape* lanovenko::parseShape(const std::string& str)
{
  if (str.find("RECTANGLE") != std::string::npos)
  {
    Shape* Rectangle = parseRectangle(str);
    return Rectangle;
  }
  if (str.find("DIAMOND") != std::string::npos)
  {
    Shape* Diamond = parseDiamond(str);
    return Diamond;
  }
  if (str.find("TRIANGLE") != std::string::npos)
  {
    Shape* Triangle = parseTriangle(str);
    return Triangle;
  }
  if (str.find("PARALLELOGRAM") != std::string::npos)
  {
    Shape* Parallelogram = parseParallelogram(str);
    return Parallelogram;
  }
  return nullptr;
}

lanovenko::Shape* lanovenko::parseRectangle(const std::string& str)
{
  std::string coordsStr = "";
  std::size_t parseCount = 0;
  double* coords = nullptr;
  for (size_t i = 0; i < str.length() - 10; i++)
  {
    coordsStr += str[i + 10];
  }
  parseCount = split(coordsStr);
  if (parseCount != 4)
  {
    return nullptr;
  }
  coords = getCoords(coordsStr, parseCount);
  point_t leftLower = { coords[0], coords[1] };
  point_t rigthUpper = { coords[2], coords[3] };
  delete[] coords;
  try
  {
    return new Rectangle{ leftLower, rigthUpper };
  }
  catch (const std::invalid_argument& e)
  {
    return nullptr;
  }
}

lanovenko::Shape* lanovenko::parseDiamond(const std::string& str)
{
  std::string coordsStr = "";
  std::size_t parseCount = 0;
  double* coords = nullptr;
  for (size_t i = 0; i < str.length() - 8; i++)
  {
    coordsStr += str[i + 8];
  }
  parseCount = split(coordsStr);
  if (parseCount != 6)
  {
    return nullptr;
  }
  coords = getCoords(coordsStr, parseCount);
  point_t p1 = { coords[0], coords[1] };
  point_t p2 = { coords[2], coords[3] };
  point_t p3 = { coords[4], coords[5] };
  delete[] coords;
  try
  {
    return new Diamond{ p1, p2, p3 };
  }
  catch (const std::invalid_argument& e)
  {
    return nullptr;
  }
}

lanovenko::Shape* lanovenko::parseTriangle(const std::string& str)
{
  std::string coordsStr = "";
  std::size_t parseCount = 0;
  double* coords = nullptr;
  for (size_t i = 0; i < str.length() - 9; i++)
  {
    coordsStr += str[i + 9];
  }
  parseCount = split(coordsStr);
  if (parseCount != 6)
  {
    return nullptr;
  }
  coords = getCoords(coordsStr, parseCount);
  point_t p1 = { coords[0], coords[1] };
  point_t p2 = { coords[2], coords[3] };
  point_t p3 = { coords[4], coords[5] };
  delete[] coords;
  try
  {
    return new Triangle{ p1, p2, p3 };
  }
  catch (const std::invalid_argument& e)
  {
    return nullptr;
  }
}

lanovenko::Shape* lanovenko::parseParallelogram(const std::string& str)
{
  std::string coordsStr = "";
  std::size_t parseCount = 0;
  double* coords = nullptr;
  for (size_t i = 0; i < str.length() - 14; i++)
  {
    coordsStr += str[i + 14];
  }
  parseCount = split(coordsStr);
  if (parseCount != 6)
  {
    return nullptr;
  }
  coords = getCoords(coordsStr, parseCount);
  point_t p1 = { coords[0], coords[1] };
  point_t p2 = { coords[2], coords[3] };
  point_t p3 = { coords[4], coords[5] };
  delete[] coords;
  try
  {
    return new Parallelogram{ p1, p2, p3 };
  }
  catch (const std::invalid_argument& e)
  {
    return nullptr;
  }
}

std::size_t lanovenko::split(const std::string& str)
{
  std::size_t res = 0;
  for (size_t i = 0; i < str.length(); i++)
  {
    std::string b = " ";
    while (str[i] != ' ' && i < str.length())
    {
      i++;
    }
    res++;
  }
  return res;
}

double* lanovenko::getCoords(const std::string& coords, size_t capacityCoords)
{
  size_t pos = 0;
  size_t nextPos = 0;
  double* array = new double[capacityCoords];
  for (size_t i = 0; i < capacityCoords; i++)
  {
    array[i] = std::stod(coords.substr(pos), &nextPos);
    pos += nextPos;
  }
  return array;
}

double* lanovenko::paraseScale(const std::string& str)
{
  std::string coordsStr = "";
  std::size_t praseCount = 0;
  double* coords = nullptr;
  for (size_t i = 0; i < str.length() - 6; i++)
  {
    coordsStr += str[i + 6];
  }
  praseCount = split(coordsStr);
  coords = getCoords(coordsStr, praseCount);
  return coords;
}
