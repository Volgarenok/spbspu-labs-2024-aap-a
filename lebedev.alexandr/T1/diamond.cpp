#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
#include "auxiliaryFunctions.hpp"

constexpr double TOLERANCE = 0.1;

lebedev::Diamond::Diamond(point_t centre, point_t vert, point_t horiz):
  concaves_(nullptr),
  concaveCount_(0),
  capacity_(0)
{
  bool isCollision = ((vert.x == horiz.x && vert.y == horiz.y)
      || (vert.x == centre.x && vert.y == centre.y)
      || (horiz.x == centre.x && horiz.y == centre.y));
  bool isValidArguments = (vert.x == centre.x && horiz.y == centre.y);

  if (!isCollision && isValidArguments)
  {
    throw std::invalid_argument("");
  }
  divideIntoConcaves(centre, vert, horiz);
  if (concaveCount_ == 0)
  {
    throw std::invalid_argument("");
  }
}

lebedev::Diamond::~Diamond()
{
  for (size_t i = 0; i < concaveCount_; i++)
  {
    delete concaves_[i];
  }
  delete[] concaves_;
}

double lebedev::Diamond::getArea() const
{
  rectangle_t rect1 = concaves_[0]->getFrameRect();
  rectangle_t rect2 = concaves_[1]->getFrameRect();
  double d1 = rect1.height + rect2.height;
  double d2 = rect1.width;
  return (d1 * d2) / 2;
}

lebedev::rectangle_t lebedev::Diamond::getFrameRect() const
{
  rectangle_t rect1 = concaves_[0]->getFrameRect();
  rectangle_t rect2 = concaves_[1]->getFrameRect();
  return { rect1.width, (rect1.height + rect2.height), getMiddlePoint(rect1.pos, rect2.pos) };
}

void lebedev::Diamond::move(point_t p)
{
  for (size_t i = 0; i < concaveCount_; i++)
  {
    concaves_[i]->move(p);
  }
}

void lebedev::Diamond::move(double dx, double dy)
{
  for (size_t i = 0; i < concaveCount_; i++)
  {
    concaves_[i]->move(dx, dy);
  }
}

void lebedev::Diamond::scale(double k)
{
  for (size_t i = 0; i < concaveCount_; i++)
  {
    concaves_[i]->scale(k);
  }
}

void lebedev::Diamond::expandArray()
{
  size_t newCapacity = (capacity_ == 0) ? 2 : capacity_ * 2;
  Concave** newArray = new Concave*[newCapacity];
  for (size_t i = 0; i < concaveCount_; i++)
  {
    newArray[i] = concaves_[i];
  }
  delete[] concaves_;
  concaves_ = newArray;
  capacity_ = newCapacity;
}

void lebedev::Diamond::divideIntoConcaves(point_t centre, point_t vert, point_t horiz)
{
  double totalArea = getCurrentDiamondArea(centre, vert, horiz);
  double coveredArea = 0;
  point_t d1Start = vert;
  point_t d1End = { vert.x, 2 * centre.y - vert.y };
  point_t d2Start = horiz;
  point_t d2End = { 2 * centre.x - horiz.x, horiz.y };
  bool isVerticalNext = true;

  while (totalArea - coveredArea > TOLERANCE)
  {
    point_t start1 = isVerticalNext ? d1Start : d2Start;
    point_t end1 = isVerticalNext ? d1End : d2End;
    point_t start2 = isVerticalNext ? d2Start : d1Start;
    point_t end2 = isVerticalNext ? d2End : d1End;

    point_t quarter1 = getMiddlePoint(start1, centre);
    point_t quarter2 = getMiddlePoint(end1, centre);
    Concave* cncv1 = new Concave(start1, start2, end2, quarter1);
    Concave* cncv2 = new Concave(end1, start2, end2, quarter2);

    if (concaveCount_ == capacity_)
    {
      expandArray();
    }

    concaves_[concaveCount_++] = cncv1;
    concaves_[concaveCount_++] = cncv2;
    coveredArea += concaves_[concaveCount_ - 2]->getArea() + concaves_[concaveCount_ - 1]->getArea();

    if (isVerticalNext)
    {
      d1Start = quarter1;
      d1End = quarter2;
    }
    else
    {
      d2Start = quarter1;
      d2End = quarter2;
    }
    isVerticalNext = !isVerticalNext;
  }
}

double lebedev::Diamond::getCurrentDiamondArea(point_t centre, point_t vert, point_t horiz) const
{
  return std::fabs((vert.y - centre.y) * (horiz.x - centre.x) * 2);
}
