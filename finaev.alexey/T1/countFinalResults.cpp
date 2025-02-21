#include "countFinalResults.hpp"
#include <iostream>
#include <iomanip>

double finaev::getSumArea(const Shape* const* shapes, size_t size)
{
  double res = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    res += shapes[i]->getArea();
  }
  return res;
}
void finaev::printFrameRect(std::ostream& out, const Shape* const* shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (i != 0)
    {
      out << " ";
    }
    rectangle_t a = shapes[i]->getFrameRect();
    double leftDownX = a.pos.x - (a.width / 2);
    double leftDownY = a.pos.y - (a.height / 2);
    double rightUpX = a.pos.x + (a.width / 2);
    double rightUpY = a.pos.y + (a.height / 2);
    out << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
  }
}
