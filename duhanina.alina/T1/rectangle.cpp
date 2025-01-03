#include "rectangle.hpp"
#include <stdexcept>
#include <cstddef>
#include <cmath>
#include "ellipse.hpp"

duhanina::Rectangle::Rectangle(point_t lt, point_t rt):
  lt_(lt),
  rt_(rt)
{
  if (lt.x >= rt.x || lt.y >= rt.y)
  {
    throw std::invalid_argument("Error in parameters");
  }
}

double duhanina::Rectangle::getArea() const
{
  return (rt_.x - lt_.x) * (rt_.y - lt_.y);
}

duhanina::rectangle_t duhanina::Rectangle::getFrameRect() const
{
  double width = rt_.x - lt_.x;
  double height = rt_.y - lt_.y;
  double posX = lt_.x + (width / 2.0);
  double posY = lt_.y + (height / 2.0);
  return { { posX, posY }, width, height };
}

void duhanina::Rectangle::move(point_t newPos)
{
  point_t pos = this->getFrameRect().pos;
  double dx = newPos.x - pos.x;
  double dy = newPos.y - pos.y;
  move(dx, dy);
}

void duhanina::Rectangle::move(double dx, double dy)
{
  lt_.x += dx;
  lt_.y += dy;
  rt_.x += dx;
  rt_.y += dy;
}

void duhanina::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Error in parameters");
  }
  point_t pos = this->getFrameRect().pos;
  lt_.x = pos.x + (lt_.x - pos.x) * k;
  lt_.y = pos.y + (lt_.y - pos.y) * k;
  rt_.x = pos.x + (rt_.x - pos.x) * k;
  rt_.y = pos.y + (rt_.y - pos.y) * k;
}

duhanina::Ellipse** duhanina::Rectangle::fillWithEllipses()
{
  size_t ellipseCount = 0;
  double rectArea = getArea();
  size_t horizontalCuts = 1;
  size_t verticalCuts = 1;
  while (true)
  {
    ellipseCount = horizontalCuts * verticalCuts;
    if (ellipseCount > 10000)
    {
      throw std::runtime_error("Maximum number of ellipses");
    }
    double ellipseWidth = (rt_.x - lt_.x) / verticalCuts;
    double ellipseHeight = (rt_.y - lt_.y) / horizontalCuts;
    Ellipse** ellipses = new Ellipse*[ellipseCount];
    for (size_t i = 0; i < verticalCuts; ++i)
    {
      for (size_t j = 0; j < horizontalCuts; ++j)
      {
        point_t center = { lt_.x + (i + 0.5) * ellipseWidth, lt_.y + (j + 0.5) * ellipseHeight };
        ellipses[i * horizontalCuts + j] = new Ellipse(center, ellipseWidth / 2, ellipseHeight / 2);
      }
    }
    double ellipsesArea = 0.0;
    for (size_t i = 0; i < ellipseCount; ++i)
    {
      ellipsesArea += ellipses[i]->getArea();
    }
    if (fabs(rectArea - ellipsesArea) <= 0.01)
    {
      return ellipses;
    }
    for (size_t i = 0; i < ellipseCount; ++i)
    {
      delete ellipses[i];
    }
    delete[] ellipses;
    if (horizontalCuts < verticalCuts)
    {
      horizontalCuts++;
    }
    else
    {
      verticalCuts++;
    }
  }
}
