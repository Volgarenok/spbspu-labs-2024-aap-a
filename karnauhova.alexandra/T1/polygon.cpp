#include "polygon.hpp"
#include <cmath>
double Polygon::getArea()
{
  double area = 0.0;
  for (size_t i = 0; i < count_; ++i)
  {
    int j = (i + 1) % count_;
    area += points_[i].x * points_[j].y;
    area -= points_[j].x * points_[i].y;
  }
  return std::abs(area) / 2;
}

rectangle_t Polygon::getFrameRect()
{
  rectangle_t rect;
  double max_x = points_[0].x;
  double min_x = points_[0].x;
  double max_y = points_[0].y;
  double min_y = points_[0].y;
  for (size_t i = 0; i < count_; ++i)
  {
    if (points_[i].x > max_x)
    {
      max_x = points_[i].x;
    }
    else if (points_[i].x < min_x)
    {
      min_x = points_[i].x;
    }
    if (points_[i].y > max_y)
    {
      max_y = points_[i].y;
    }
    else if (points_[i].y < min_y)
    {
      min_y = points_[i].y;
    }
  }
  rect.width = max_x - min_x;
  rect.height = max_y - min_y;
  rect.pos.x = min_x + (rect.width / 2);
  rect.pos.y = min_y + (rect.height / 2);
  return rect;
}

void Polygon::move(double x, double y)
{
  for (size_t i = 0; i < count_; ++i)
  {
    points_[i].x += x;
    points_[i].y += y;
  }
}

void Polygon::move(point_t t)
{
  point_t centr = getFrameRect().pos;
  double dif_x = t.x - centr.x;
  double dif_y = t.y - centr.y;
  for (size_t i = 0; i < count_; i++)
  {
    points_[i].x += dif_x;
    points_[i].y += dif_y;
  }
}

void Polygon::scale(point_t t, double k)
{
  for (size_t i = 0; i < count_; i++)
  {
     points_[i].x = t.x + (points_[i].x - t.x) * k;
     points_[i].y = t.y + (points_[i].y - t.y) * k;
  }
}
