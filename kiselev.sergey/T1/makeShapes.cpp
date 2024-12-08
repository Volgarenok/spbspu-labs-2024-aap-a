#include "makeShapes.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
#include "complexquad.hpp"
#include "diamond.hpp"
namespace
{
  kiselev::point_t intersectionPoint(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3, kiselev::point_t p4)
  {
    double leftDownX = std::min(std::min(p1.x, p2.x), std::min(p3.x, p4.x));
    double leftDownY = std::min(std::min(p1.y, p2.y), std::min(p3.y, p4.y));
    double rightUpX = std::max(std::max(p1.x, p2.x), std::max(p3.x, p4.x));
    double rightUpY = std::max(std::max(p1.y, p2.y), std::max(p3.y, p4.y));
    return { leftDownX + (rightUpX - leftDownX) / 2, leftDownY + (rightUpY - leftDownY) / 2 };
  }
  bool isTriangle(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3)
  {
    double lenght1 = std::sqtr(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
    double lenght2 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));
    double lenght3 = std::sqrt(std::pow(p2.x - p3.x, 2) + std::pow(p2.y - p3.y, 2));
    if (lenght1 < lenght2 + lenght3 || lenght2 < lenght1 + lenght3 || lenght3 < lenght1 + lenght2)
    {
      return true;
    }
    return false;
  }

}
kiselev::Rectangle* kiselev::make_rectangle(std::istream& input)
{
  double x1 = 0;
  double y1 = 0;
  double x2 = 0;
  double y2 = 0;
  input >> x1 >> y1 >> x2 >> y2;
  if (x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  kiselev::Rectangle* rect = new kiselev::Rectangle({ x1, y1 }, { x2, y2 });
  return rect;
}
kiselev::point_t kiselev::make_scale(std::istream& input)
{
  double x = 0;
  double y = 0;
  input >> x >> y;
  return { x, y };
}
kiselev::Diamond* kiselev::make_diamond(std::istream& input)
{
  double x1 = 0;
  double x2 = 0;
  double x3 = 0;
  double y1 = 0;
  double y2 = 0;
  double y3 = 0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (x1 == x2 && y1 == y3)
  {

    kiselev::Diamond* diam = new kiselev::Diamond({ x1, y1 }, { x2, y2 }, { x3, y3 });
    return diam;
  }
  else if (x1 == x3 && y1 == y2)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x1, y1 }, { x3, y3 }, { x2, y2 });
    return diam;
  }
  else if (x2 == x1 && y2 == y3)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x2, y2 }, { x1, y1 }, { x3, y3 });
    return diam;
  }
  else if (x2 == x3 && y2 == y1)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x2, y2 }, { x3, y3 }, { x1, y1 });
    return diam;
  }
  else if (x3 == x1 && y3 == y2)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x3, y3 }, { x1, y1 }, { x2, y2 });
    return diam;
  }
  else if (x3 == x2 && y3 == y1)
  {
    kiselev::Diamond* diam = new kiselev::Diamond({ x3, y3 }, { x2, y2 }, { x1, y1 });
    return diam;
  }
  else
  {
    throw std::invalid_argument("");
  }
}
kiselev::Complexquad* kiselev::make_complexquad(std::istream& input)
{
  double x1 = 0;
  double x2 = 0;
  double x3 = 0;
  double x4 = 0;
  double y1 = 0;
  double y2 = 0;
  double y3 = 0;
  double y4 = 0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  point_t p1 = { x1, y1 };
  point_t p2 = { x2, y2 };
  point_t p3 = { x3, y3 };
  point_t p4 = { x4, y4 };
  point_t centre = intersectionPoint(p1, p2, p3, p4);
  if (!isTriangle(p1, p4, centre) || !isTriangle(p2, p3, centre))
  {
    throw std::invalid_argument("");
  }
  kiselev::Complexquad* comp = new kiselev::Complexquad(p1, p2, p3, p4);
  return comp;
}

