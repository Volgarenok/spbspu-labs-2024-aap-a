#include "tools.hpp"
#include <cmath>
#include <iostream>

namespace ivanova
{
  bool operator==(const ivanova::point_t a, const ivanova::point_t b)
  {
    return ((a.x == b.x) && (a.y == b.y));
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
    throw std::invalid_argument("Invalid scale ratio: ratio must be positive.");
  }
  for (size_t i = 0; i < size; ++i)
  {
    if (shps[i] != nullptr)
    {
      ivanova::point_t begin = shps[i]->getFrameRect().pos;
      shps[i]->move(scalePoint);
      ivanova::point_t newCenter = shps[i]->getFrameRect().pos;

      ivanova::point_t offset = {k * (begin.x - newCenter.x),k * (begin.y - newCenter.y)};
      shps[i]->scale(k);
      shps[i]->move(offset);
    }
  }
}
