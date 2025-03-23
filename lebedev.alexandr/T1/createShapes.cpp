#include "createShapes.hpp"

void lebedev::sortPoints(point_t& p1, point_t& p2, point_t& p3)
{
  if (p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y))
  {
    std::swap(p1, p2);
  }
  if (p1.x > p3.x || (p1.x == p3.x && p1.y > p3.y))
  {
    std::swap(p1, p3);
  }
  if (p2.x > p3.x || (p2.x == p3.x && p2.y > p3.y))
  {
    std::swap(p2, p3);
  }
}

lebedev::point_t lebedev::readPoint(std::istream& input)
{
  double x = 0, y = 0;
  input >> x >> y;
  return { x, y };
}

lebedev::point_t lebedev::chooseScalePoint(std::istream& input)
{
  return readPoint(input);
}

lebedev::Rectangle* lebedev::createRectangle(std::istream& input)
{
  point_t p1 = readPoint(input);
  point_t p2 = readPoint(input);
  return new Rectangle(p1, p2);
}

lebedev::Diamond* lebedev::createDiamond(std::istream& input)
{
  point_t p1 = readPoint(input);
  point_t p2 = readPoint(input);
  point_t p3 = readPoint(input);

  sortPoints(p1, p2, p3);
  return new Diamond(p2, p3, p1);
}

lebedev::Concave* lebedev::createConcave(std::istream& input)
{
  point_t p1 = readPoint(input);
  point_t p2 = readPoint(input);
  point_t p3 = readPoint(input);
  point_t p4 = readPoint(input);

  return new Concave(p1, p2, p3, p4);
}
