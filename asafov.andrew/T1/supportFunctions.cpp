#include "supportFunctions.hpp"

void asafov::scalePoint(asafov::point_t& point, asafov::point_t fpoint, double scale)
{
  point.x += (point.x - fpoint.x) * (scale - 1);
  point.y += (point.y - fpoint.y) * (scale - 1);
}

asafov::point_t asafov::getPoint(std::istream& in)
{
  point_t point;
  in >> point.x;
  in >> point.y;
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

void asafov::outputFrameRect(Shape* shape, std::ostream& out)
{
  rectangle_t rect = shape->getFrameRect();
  out << rect.pos.x - rect.width / 2;
  out << ' ' << rect.pos.y - rect.height / 2;
  out << ' ' << rect.pos.x + rect.width / 2;
  out << ' ' << rect.pos.y + rect.height / 2;
}
