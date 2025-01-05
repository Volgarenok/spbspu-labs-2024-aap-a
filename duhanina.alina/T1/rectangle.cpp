#include "rectangle.hpp"
#include <stdexcept>
#include "destroy.hpp"
#include "printResult.hpp"
#include "movingPoint.hpp"

duhanina::Rectangle::Rectangle(const point_t& lt, const point_t& rt):
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

void duhanina::Rectangle::move(const point_t& newPos)
{
  point_t pos = this->getFrameRect().pos;
  point_t offset = calculateOffset(pos, newPos);
  move(offset.x, offset.y);
}

void duhanina::Rectangle::move(double dx, double dy)
{
  movePoint(lt_, dx, dy);
  movePoint(rt_, dx, dy);
}

void duhanina::Rectangle::scale(double k)
{
  point_t pos = this->getFrameRect().pos;
  lt_ = scalePoint(lt_, pos, k);
  rt_ = scalePoint(rt_, pos, k);
}

duhanina::Shape** duhanina::Rectangle::fillWithEllipses()
{
  size_t ellipseCount = 0;
  double rectArea = getArea();
  size_t horizontalCuts = 1;
  size_t verticalCuts = 1;
  double ellipsesArea = 0.0;
  Shape** ellipses = nullptr;
  while (std::fabs(rectArea - ellipsesArea) >= 0.01)
  {
    ellipseCount = horizontalCuts * verticalCuts;
    if (ellipseCount > 10000)
    {
      throw std::runtime_error("Maximum number of ellipses");
    }
    ellipses = new Shape*[ellipseCount] {};
    double ellipseWidth = (rt_.x - lt_.x) / verticalCuts;
    double ellipseHeight = (rt_.y - lt_.y) / horizontalCuts;
    for (size_t i = 0; i < verticalCuts; ++i)
    {
      for (size_t j = 0; j < horizontalCuts; ++j)
      {
        point_t center = { lt_.x + (i + 0.5) * ellipseWidth, lt_.y + (j + 0.5) * ellipseHeight };
        ellipses[i * horizontalCuts + j] = new Ellipse(center, ellipseWidth / 2, ellipseHeight / 2);
      }
    }
    ellipsesArea = calcArea(ellipses, ellipseCount);
    if (std::fabs(rectArea - ellipsesArea) >= 0.01)
    {
      destroy(ellipses, ellipseCount);
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
  return ellipses;
}
