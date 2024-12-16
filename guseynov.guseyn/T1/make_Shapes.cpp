#include "make_Shapes.hpp"

#include <cstring>
#include <exception>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

namespace
{
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

  void getFrRectCords(guseynov::rectangle_t & rect, double & lbx, double & lby, double & rtx, doub>
  {
    lbx = rect.pos.x - rect.width / 2;
    lby = rect.pos.y - rect.height / 2;
    rtx = rect.pos.x + rect.width / 2;
    rty = rect.pos.y + rect.height / 2;
  }

  void scaleRelativeTo(guseynov::Shape * shp, point_t p, double k)
  {
    point_t firstRect = shp->getFrameRect().pos;
    shp->move(p);
    point_t secondRect = shp->getFrameRect().pos;
    point_t vector = {(secondRect.x - firstRect.x) * k, (secondRect.y - firstRect.y)>  shp->scale(k);
    shp->move(-vector.x, -vector.y);
  }
}

size_t guseynov::makeShape(const char *line, guseynov::Shape **shp, size_t & sch, point_t & p, double & k)
{
  if (line[0] == '\0')
    {
      return 2;
    }
  char *arr = std::strtok(line, " ");
  try
  {
    if (!std::strcmp(arr, "RECTANGLE"))
    {
      double numbers[4] = {0, 0, 0, 0};
      readNum(numbers, 4);
      Rectangle *Rect = new Rectangle({numbers[0], numbers[1]}, {numbers[2], numbers[3]});
      shp[sch++] = Rect;
      return 0;
    }
    if (!std::strcmp(arr, "SQUARE"))
    {
      double numbers[3] = {0, 0, 0};
      readNum(numbers, 3);
      Square *Squa = new Square({numbers[0], numbers[1]}, numbers[2]);
      shp[sch++] = Squa;
      return 0;
    }
    if (!std::strcmp(arr, "PARALLELOGRAM"))
    {
      double numbers[6] = {0, 0, 0, 0, 0, 0};
      readNum(numbers, 6);
      Parallelogram *Para = new Parallelogram({numbers[0], numbers[1]}, {numbers[2], numbers[3]}, {numbers[4], numbers[5]});
      shp[sch++] = Para;
      return 0;
    }
  }
  catch (const std::invalid_argument & e)
  {
    return 2;
  }
  if (std::strcmp(arr, "SCALE"))
  {
    double numbers[3] = {0, 0, 0};
    readNum(numbers, 3);
    p = {numbers[0], numbers[1]}
    k = numbers[2];
    return 1;
  }
}

void guseynov::clearShapes(guseynov::Shape **shp, size_t currentIndx)
{
  for (size_t i; i < currentIndx; i++)
  {
    delete[] shp[i];
  }
}

double guseynov::getAreaSum(guseynov::Shape **shp, size_t Num)
{
  double sum = 0;
  for (size_t i = 0; i < Num; i++)
  {
    sum += shp[i]->getArea();
  }
  return sum;
}

void guseynov::printFrRectCords(std::ostream & out, guseynov::Shape **shp, size_t Num)
{
  for (size_t i = 0; i < Num; i++)
  {
    double lbx = 0, lby = 0, rtx = 0, rty = 0;
    guseynov::rectangle_t rect = shp[i]->getFrameRect();
    getFrRectCords(rect, lbx, lby, rtx, rty);
    out << " " << lbx << " " << lby << " " << rtx << " " << rty;
  }
  out << "\n";
}

void guseynov::scaleAllRelativeTo(Shape **shp, size_t Num, point_t p, double k)
{
  if (k <= 0)
  {
    throw;
  }
  for (size_t i = 0; i < Num; i++)
  {
    scaleRelativeTo(shp[i], p, k);
  }
}

