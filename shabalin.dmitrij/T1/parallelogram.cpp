#include "parallelogram.hpp"
#include "base-types.hpp"
#include "creatingOfShape.hpp"
#include <stdexcept>

shabalin::Parallelogram::Parallelogram(point_t firstP, point_t secondP, point_t thirdP):
  p1_(firstP),
  p2_(secondP),
  p3_(thirdP)
{
  if (!((p1_.y == p2_.y) || (p1_.y == p3_.y) || (p2_.y == p3_.y)))
  {
    throw std::logic_error("The provided points do not form a parallelogram!");
  }
  if ((p1_.x == 0) && (p1_.y == 0) && (p2_.x == 0) && (p2_.y == 0) && (p3_.x == 0) && (p3_.y == 0))
  {
    throw std::logic_error("Invalid points for parallelogram!");
  }
}

double shabalin::Parallelogram::getArea() const
{
  rectangle_t dataFrameOfPar = getFrameRect();
  if (p1_.y == p2_.y)
  {
    return std::abs((p1_.x - p2_.x) * dataFrameOfPar.height);
  }
  else
  {
    return std::abs((p2_.x - p3_.x) * dataFrameOfPar.height);
  }
}

shabalin::rectangle_t shabalin::Parallelogram::getFrameRect() const
{
  double width = std::abs(p2_.x - p1_.x) + std::abs(p2_.x - p3_.x);
  double height = 0;
  if (p2_.y == p1_.y)
  {
    height = std::abs(p3_.y - p2_.y);
  }
  else
  {
    height = std::abs(p2_.y - p1_.y);
  }

  point_t midPointOfRect = {0, 0};
  if (p1_.x <= p2_.x && p1_.x <= p3_.x)
  {
    midPointOfRect.x = p1_.x + (width / 2.0);
  }
  else if (p2_.x <= p1_.x && p2_.x <= p3_.x)
  {
    midPointOfRect.x = p2_.x + (width / 2.0);
  }
  else
  {
    midPointOfRect.x = p3_.x + (width / 2.0);
  }

  if (p1_.y > p2_.y || p1_.y > p3_.y)
  {
    midPointOfRect.y = p1_.y - (height / 2.0);
  }
  else
  {
    midPointOfRect.y = p1_.y + (height / 2.0);
  }

  return {width, height, midPointOfRect};
}

void shabalin::Parallelogram::move(const point_t point)
{
  rectangle_t rectOfParal = getFrameRect();
  double delX = point.x - rectOfParal.pos.x;
  double delY = point.y - rectOfParal.pos.y;
  move(delX, delY);
}

void shabalin::Parallelogram::move(const double delX, const double delY)
{
  point_t * pointsArray[3] = {&p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; i++)
  {
    pointsArray[i]->x += delX;
    pointsArray[i]->y += delY;
  }
}

void shabalin::Parallelogram::scaleShape(const double k)
{
  rectangle_t rectOfParal = getFrameRect();
  scaleForParAndDiam(rectOfParal, p1_, p2_, p3_, k);
}
