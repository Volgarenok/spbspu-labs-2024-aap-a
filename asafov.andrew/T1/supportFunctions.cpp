#include "supportFunctions.hpp"
#include <algorithm>
#include "cmath"

void asafov::scalePoint(asafov::point_t& point, asafov::point_t fpoint, double scale)
{
  point.x += (point.x - fpoint.x) * (scale - 1);
  point.y += (point.y - fpoint.y) * (scale - 1);
}

asafov::point_t asafov::getPoint(std::istream& in)
{
  double x = 0;
  in >> x;
  double y = 0;
  in >> y;
  point_t point = { x, y };
  return point;
}

void asafov::isotropicScale(Shape* sh, point_t pos, double scale)
{
  point_t centr = sh->getFrameRect().pos;
  sh->move(pos);
  double vectorx = scale * centr.x - scale * sh->getFrameRect().pos.x;
  double vectory = scale * centr.y - scale * sh->getFrameRect().pos.y;
  sh->scale(scale);
  sh->move(vectorx, vectory);
}

void asafov::doUnsafeIsotropicScale(Shape* sh, point_t pos, double scale)
{
  point_t centr = sh->getFrameRect().pos;
  sh->move(pos);
  double vectorx = scale * centr.x - scale * sh->getFrameRect().pos.x;
  double vectory = scale * centr.y - scale * sh->getFrameRect().pos.y;
  sh->doUnsafeScale(scale);
  sh->move(vectorx, vectory);
}

void asafov::outputFrameRect(Shape* shape, std::ostream& out)
{
  rectangle_t rect = shape->getFrameRect();
  out << rect.pos.x - rect.width / 2;
  out << ' ' << rect.pos.y - rect.height / 2;
  out << ' ' << rect.pos.x + rect.width / 2;
  out << ' ' << rect.pos.y + rect.height / 2;
}

double asafov::getPi()
{
  return std::atan(1.0) * 4;
}

void asafov::increaseDelta(point_t& point, double dx, double dy)
{
  point.x += dx;
  point.y += dy;
}

double asafov::getCenterDelta(double one, double two, double three)
{
  return std::max( { one, two, three } ) - std::min( { one, two, three } );
}

double asafov::getCenterDelta(double one, double two, double three, double four)
{
  return std::max( { one, two, three, four } ) - std::min( { one, two, three, four } );
}

void asafov::getPoints(point_t* points, size_t size, std::istream& in)
{
  for (size_t i = 0; i < size; i++)
  {
    points[i] = getPoint(in);
  }
}

double asafov::getLength(point_t one, point_t two)
{
  return std::pow(std::pow((one.x - two.x), 2.0) + std::pow((one.y - two.y), 2.0), 0.5);
}

double asafov::getTotalArea(asafov::Shape** shapes, size_t count)
{
  double area = 0;
  for (size_t i = 0; i < count; i++)
  {
    area += shapes[i]->getArea();
  }
  return area;
}
