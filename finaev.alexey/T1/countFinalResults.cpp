#include "countFinalResults.hpp"
#include <iostream>

namespace
{
  void printOneRect(std::ostream& out, finaev::rectangle_t a)
  {
    double leftDownX = a.pos.x - (a.width / 2);
    double leftDownY = a.pos.y - (a.height / 2);
    double rightUpX = a.pos.x + (a.width / 2);
    double rightUpY = a.pos.y + (a.height / 2);
    out << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
  }
}

double finaev::getSumArea(const Shape* const* shapes, size_t size)
{
  double res = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    res += shapes[i]->getArea();
  }
  return res;
}
void finaev::printFrameRect(std::ostream& out, const Shape* const* shapes, size_t size)
{
  printOneRect(out, shapes[0]->getFrameRect());
  for (size_t i = 0; i < size; ++i)
  {
    out << " ";
    printOneRect(out, shapes[i]->getFrameRect());
  }
}
