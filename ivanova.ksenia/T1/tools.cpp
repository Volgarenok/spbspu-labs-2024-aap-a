#include "tools.hpp"
#include <cmath>
#include <iostream>

namespace ivanova
{
  bool operator==(const ivanova::point_t a, const ivanova::point_t b)
  {
    return ((a.x == b.x) && (a.y == b.y));
  }

  double orientation(const point_t& p1, const point_t& p2, const point_t& p3)
  {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
  }

  bool isOnSegment(const point_t& p1, const point_t& p2, const point_t& p3)
  {
    return std::fmin(p1.x, p2.x) <= p3.x && p3.x <= std::fmax(p1.x, p2.x) &&
           std::fmin(p1.y, p2.y) <= p3.y && p3.y <= std::fmax(p1.y, p2.y);
  }

  bool areSegmentsIntersecting(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4)
  {
    double o1 = orientation(p1, p2, p3);
    double o2 = orientation(p1, p2, p4);
    double o3 = orientation(p3, p4, p1);
    double o4 = orientation(p3, p4, p2);
    if ((o1 * o2 < 0) && (o3 * o4 < 0))
    {
      return true;
    }

    if (o1 == 0 && isOnSegment(p1, p2, p3))
    {
      return true;
    }
    if (o2 == 0 && isOnSegment(p1, p2, p4))
    {
      return true;
    }
    if (o3 == 0 && isOnSegment(p3, p4, p1))
    {
      return true;
    }
    if (o4 == 0 && isOnSegment(p3, p4, p2))
    {
      return true;
    }
    return false;
  }
}

double ivanova::vectorLength(point_t a, point_t b)
{
  return std::sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void ivanova::deleteShapes(Shape** shps, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (shps[i] != nullptr)
    {
      delete shps[i];
    }
  }
}

double ivanova::getSumArea(Shape **shps, size_t size)
{
  double sum = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (shps[i] != nullptr)
    {
      sum += shps[i]->getArea();
    }
  }
  return sum;
}

void ivanova::printFrameRect(Shape** shps, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (shps[i] != nullptr)
    {
      ivanova::rectangle_t rect = shps[i]->getFrameRect();
      double leftDownX = rect.pos.x - rect.width / 2;
      double leftDownY = rect.pos.y - rect.height / 2;
      double rightUpX = rect.pos.x + rect.width / 2;
      double rightUpY = rect.pos.y + rect.height / 2;
      std::cout << ' ' << leftDownX << ' ' << leftDownY << ' ' << rightUpX << ' ' << rightUpY;
    }
  }
  std::cout << '\n';
}

void ivanova::scale(Shape** shps, size_t size, point_t scalePoint, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scale ratio!");
  }
  for (size_t i = 0; i < size; ++i)
  {
    if (shps[i] != nullptr)
    {
      ivanova::point_t begin = shps[i]->getFrameRect().pos;
      ivanova::point_t offset = {scalePoint.x + k * (begin.x - scalePoint.x),scalePoint.y + k * (begin.y - scalePoint.y)};
      shps[i]->move(offset);
      shps[i]->scale(k);
    }
  }
}
