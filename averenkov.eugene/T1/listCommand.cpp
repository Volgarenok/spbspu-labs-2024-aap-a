#include "listCommand.hpp"

namespace
{
  averenkov::point_t getLeftBot(const averenkov::rectangle_t& rect)
  {
    return { (rect.pos.x - (rect.width / 2)), (rect.pos.y - (rect.height / 2)) };
  }

  averenkov::point_t getRightTop(const averenkov::rectangle_t& rect)
  {
    return { (rect.pos.x + (rect.width / 2)), (rect.pos.y + (rect.height / 2)) };
  }
}

void averenkov::destroy(Shape** list, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete list[i];
  }
}

double averenkov::calculateTotalArea(const Shape* const* list, size_t count)
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
  if (factor <= 0)
  {
    throw std::logic_error("Invalid input");
  }
  for (size_t i = 0; i < count; ++i)
  {
    list[i]->scale(factor);
    point_t pos = list[i]->getFrameRect().pos;
    double xplus = scale_center.x - pos.x;
    double yplus = scale_center.y - pos.y;
    xplus *= factor;
    yplus *= factor;
    point_t newpos =
    {
      scale_center.x + (pos.x - scale_center.x) * factor,
      scale_center.y + (pos.y - scale_center.y) * factor
    };
    list[i]->move(newpos);
  }
}

void averenkov::printFigure(const Shape* shap)
{
  averenkov::rectangle_t rect = shap->getFrameRect();
  std::cout << getLeftBot(rect).x << " ";
  std::cout << getLeftBot(rect).y << " ";
  std::cout << getRightTop(rect).x << " ";
  std::cout << getRightTop(rect).y;
}

void averenkov::printList(const Shape* const* list, size_t count)
{
  std::cout << calculateTotalArea(list, count);
  for (size_t i = 0; i < count; i++)
  {
    std::cout << " ";
    printFigure(list[i]);
  }
}
