#include "listCommand.hpp"
#include "shapeScale.hpp"

void averenkov::destroy(Shape** list, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete list[i];
  }
}

double averenkov::calculateTotalArea(Shape** list, size_t count)
{
  double sum = 0;
  for (size_t i = 0; i < count; i++)
  {
    sum += list[i]->getArea();
  }
  return sum;
}

void averenkov::scaleList(Shape** list, size_t count, point_t scale_center, double factor)
{
  for (size_t i = 0; i < count; ++i)
  {
    list[i]->scale(factor);
    averenkov::shapeScale(list[i], scale_center, factor);
  }
}

void averenkov::printList(Shape** list, size_t count)
{
  std::cout << calculateTotalArea(list, count);
  for (size_t i = 0; i < count; i++)
  {
    averenkov::rectangle_t rect = list[i]->getFrameRect();
    std::cout << " " << averenkov::getLeftBot(rect).x << " ";
    std::cout << averenkov::getLeftBot(rect).y << " ";
    std::cout << averenkov::getRightTop(rect).x << " ";
    std::cout << averenkov::getRightTop(rect).y << "\n";
  }
}
