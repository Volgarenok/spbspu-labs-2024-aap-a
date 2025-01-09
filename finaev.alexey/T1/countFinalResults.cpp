#include "countFinalResults.hpp"
#include <iostream>
#include <iomanip>

double finaev::getSumArea(Shape** shapes, const size_t size)
{
  double res = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    res += shapes[i]->getArea();
  }
  return res;
}
void finaev::printFrameRect(std::ostream& out, Shape** shapes, const size_t size)
{
  rectangle_t a = shapes[0]->getFrameRect();
  double leftDownX = a.pos.x - (a.width / 2);
  double leftDownY = a.pos.y - (a.height / 2);
  double rightUpX = a.pos.x + (a.width / 2);
  double rightUpY = a.pos.y + (a.height / 2);
  for (size_t i = 1; i < size; i++)
  {
    out << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY << " ";
    rectangle_t a = shapes[i]->getFrameRect();
    double leftDownX = a.pos.x - (a.width / 2);
    double leftDownY = a.pos.y - (a.height / 2);
    double rightUpX = a.pos.x + (a.width / 2);
    double rightUpY = a.pos.y + (a.height / 2);
  }
  out << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
}
