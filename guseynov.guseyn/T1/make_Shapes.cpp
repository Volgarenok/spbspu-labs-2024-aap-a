#include "make_Shapes.hpp"

#include <cstring>
#include <exception>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

void readNum(double * numbers, size_t k)
{
  char * current = nullptr;
  for (size_t i = 0; i < k; ++i)
  {
    current = std::strtok(nullptr, " ");
    if (!current)
    {
      break;
    }
    numbers[i] = std::atof(current);
  }
}
size_t guseynov::makeShape(const char *line, Shape **shp, size_t sch, point_t p, double k)
{
  if (line[0] == '\0')
    {
      return 1;
    }
  char *arr = std::strtok(line, " ");
  try
  {
    if (!std::strcmp(arr, "RECTANGLE"))
    {
      double numbers[4] = {0, 0, 0, 0};
      readNum(numbers, 4);
      Rectangle *Rect = new Rectangle({numbers[0], numbers[1]}, {numbers[2], numbers[3]});
      shp[sch] = Rect;
      return 0;
    }
    if (!std::strcmp(arr, "SQUARE"))
    {
      double numbers[3] = {0, 0, 0};
      readNum(numbers, 3);
      Square *Squa = new Square({numbers[0], numbers[1]}, numbers[2]);
      shp[sch] = Squa;
      return 0;
    }
    if (!std::strcmp(arr, "PARALLELOGRAM"))
    {
      double numbers[6] = {0, 0, 0, 0, 0, 0};
      readNum(numbers, 6);
      Parallelogram *Para = new Parallelogram({numbers[0], numbers[1]}, {numbers[2], numbers[3]}, {numbers[4], numbers[5]});
      shp[sch] = Para;
      return 0;
    }
  }
  catch (const std::invalid_argument & e)
  {
    return 1;
  }
  if (std::strcmp(arr, "SCALE"))
  {
    double numbers[3] = {0, 0, 0};
    readNum(numbers, 3);
    p = {numbers[0], numbers[1]}
    k = numbers[2];
    return 2;
  }
}









