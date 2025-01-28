#include "rectanglepoints.hpp"

averenkov::point_t averenkov::getLeftBot(const averenkov::rectangle_t& rect)
{
  return { (rect.pos.x - (rect.width / 2)), (rect.pos.y - (rect.height / 2)) };
}

averenkov::point_t averenkov::getRightTop(const averenkov::rectangle_t& rect)
{
  return { (rect.pos.x + (rect.width / 2)), (rect.pos.y + (rect.height / 2)) };
}
