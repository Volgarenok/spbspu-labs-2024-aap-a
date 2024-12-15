#include "countFinalResults.h"
#include <iostream>
#include <iomanip>

double finaev::getSumArea(finaev::Shape** shapes, size_t size)
{
  double res = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    if (shapes[i] != nullptr)
    {
      res += shapes[i]->getArea();
    }
  }
  return res;
}
void finaev::printFrameRect(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (shapes[i] != nullptr)
    {
      rectangle_t a = shapes[i]->getFrameRect();
      double leftDownX = a.pos.x - (a.wedth / 2);
      double leftDownY = a.pos.y - (a.height / 2);
      double rightUpX = a.pos.x + (a.wedth / 2);
      double rightUpY = a.pos.y + (a.height / 2);
      std::cout << std::fixed << std::setprecision(1) << leftDownX << " ";
      std::cout << std::fixed << std::setprecision(1) << leftDownY << " ";
      std::cout << std::fixed << std::setprecision(1) << rightUpX << " ";
      std::cout << std::fixed << std::setprecision(1) << rightUpY << " ";
    }
  }
}
