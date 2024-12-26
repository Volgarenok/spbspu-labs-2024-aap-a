#include "make_Shapes.hpp"

#include <cstring>

namespace
{
  void getFrRectCords(guseynov::rectangle_t & rect, double & lbx, double & lby, double & rtx, double & rty)
  {
    lbx = rect.pos.x - rect.width / 2;
    lby = rect.pos.y - rect.height / 2;
    rtx = rect.pos.x + rect.width / 2;
    rty = rect.pos.y + rect.height / 2;
  }

  void scaleRelativeTo(guseynov::Shape * shp, guseynov::point_t p, double k)
  {
    guseynov::point_t firstRect = shp->getFrameRect().pos;
    shp->move(p);
    guseynov::point_t secondRect = shp->getFrameRect().pos;
    shp->scale(k);
    guseynov::point_t offset;
    offset.x = (secondRect.x - firstRect.x) * k;
    offset.y = (secondRect.y - firstRect.y) * k;
    shp->move(-offset.x, -offset.y);
  }

  void rakirovka(double & x, double & x2, double & y, double & y2)
  {
    double timeX, timeY;
    timeX = x2;
    x2 = x;
    x = timeX;
    timeY = y2;
    y2 = y;
    y = timeY;
  }
}

guseynov::Rectangle* guseynov::makeRectangle(std::istream& in)
{
  double x0 = 0, y0 = 0, x1 = 0, y1 = 0;
  in >> x0 >> y0 >> x1 >> y1;
  if (x0 >= x1 || y0 >= y1)
  {
    return nullptr;
  }
  point_t leftLowP, rightHighP;
  leftLowP.x = x0;
  leftLowP.y = y0;
  rightHighP.x = x1;
  rightHighP.y = y1;
  Rectangle *rectangle = new Rectangle(leftLowP, rightHighP);
  return rectangle;
}

guseynov::Square* guseynov::makeSquare(std::istream& in)
{
  double x0, y0, length;
  in >> x0 >> y0 >> length;
  if (length <= 0)
  {
    return nullptr;
  }
  point_t leftLowP;
  leftLowP.x = x0;
  leftLowP.y = y0;
  Square *square = new Square(leftLowP, length);
  return square;
}

guseynov::Parallelogram* guseynov::makeParallelogram(std::istream& in)
{
  double x0, y0, x1, y1, x2, y2;
  in >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
  if (y0 != y1 || x0 >= x1)
  {
    return nullptr;
  }
  point_t leftLowP, leftHighP, rightLowP;
  leftLowP.x = x0;
  leftLowP.y = y0;
  leftHighP.x = x2;
  leftHighP.y = y2;
  rightLowP.x = x1;
  rightLowP.y = y1;
  Parallelogram *parallelogram = new Parallelogram(leftLowP, rightLowP, leftHighP);
  return parallelogram;
}

guseynov::Diamond* guseynov::makeDiamond(std::istream& in)
{
  double x0, y0, x1, y1, x2, y2;
  in >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
  if (x0 == x1)
  {
    if (y0 > y1)
    {
      rakirovka(x1, x2, y1, y2);
    }
    else if (y1 > y0)
    {
      rakirovka(x1, x2, y1, y2);
      rakirovka(x0, x2, y0, y2);
    }
    else
    {
      return nullptr;
    }
  }
  else if (x1 == x2)
  {
    if (y1 > y2)
    {
      rakirovka(x0, x1, y0, y1);
    }
    else if (y2 > y1)
    {
      rakirovka(x1, x2, y1, y2);
      rakirovka(x0, x1, y1, y1);
    }
    else
    {
      return nullptr;
    }
  }
  else if (x0 != x2)
  {
    return nullptr;
  }
  point_t highP, rightP, center;
  highP.x = x0;
  highP.y = y0;
  rightP.x = x1;
  rightP.y = y1;
  center.x = x2;
  center.y = y2;
  Diamond *diamond = new Diamond(highP, rightP, center);
  return diamond;
}

void guseynov::clearShapes(guseynov::Shape **shp, size_t currentIndx)
{
  for (size_t i = 0; i < currentIndx; i++)
  {
    if (shp[i] != nullptr)
    {
      delete shp[i];
    }
  }
}

double guseynov::getAreaSum(guseynov::Shape **shp, size_t Num)
{
  double sum = 0;
  for (size_t i = 0; i < Num; i++)
  {
    if (shp[i] != nullptr)
    {
      sum += shp[i]->getArea();
    }
  }
  return sum;
}

void guseynov::printFrRectCords(std::ostream & out, guseynov::Shape **shp, size_t Num)
{
  for (size_t i = 0; i < Num; i++)
  {
    if (shp[i] != nullptr)
    {
      double lbx = 0, lby = 0, rtx = 0, rty = 0;
      guseynov::rectangle_t rect = shp[i]->getFrameRect();
      getFrRectCords(rect, lbx, lby, rtx, rty);
      out << " " << lbx << " " << lby << " " << rtx << " " << rty;
    }
  }
  out << "\n";
}

void guseynov::scaleAllRelativeTo(Shape **shp, size_t Num, guseynov::point_t p, double k)
{
  for (size_t i = 0; i < Num; i++)
  {
    if (shp[i] != nullptr)
    {
      scaleRelativeTo(shp[i], p, k);
    }
  }
}

