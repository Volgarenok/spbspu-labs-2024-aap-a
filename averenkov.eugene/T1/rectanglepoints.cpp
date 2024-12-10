#include "rectanglepoints.hpp"

averenkov::point_t averenkov::getLeftBot(const averenkov::rectangle_t r)
{
  return { (r.pos.x - (r.width / 2)), (r.pos.y - (r.height / 2)) };
}

averenkov::point_t averenkov::getRightTop(const averenkov::rectangle_t r)
{
  return { (r.pos.x + (r.width / 2)), (r.pos.y + (r.height / 2)) };
}
