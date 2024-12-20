#include "composition.hpp"

#include <algorithm>
#include <stdexcept>
#include <memf.hpp>
#include "shape_scale.hpp"

using rychkov::Shape;

Shape** rychkov::composition::allocate(size_t size)
{
  return static_cast< rychkov::Shape** >(malloc(size * sizeof(rychkov::Shape*)));
}
Shape** rychkov::composition::reallocate(Shape** shapes, size_t nAllocated, size_t newSize)
{
  char* temp = realloc(reinterpret_cast< char* >(shapes), nAllocated * sizeof(Shape*),
        newSize * sizeof(Shape*));
  return reinterpret_cast< Shape** >(temp);
}
void rychkov::composition::deallocate(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    shapes[i]->~Shape();
    free(shapes[i]);
  }
  free(shapes);
}
Shape** rychkov::composition::push_back(Shape** shapes, size_t& size, size_t& nAllocated, Shape* value)
{
  if (size >= nAllocated)
  {
    Shape** temp = reallocate(shapes, nAllocated, size * 2);
    if (!temp)
    {
      return nullptr;
    }
    shapes = temp;
    nAllocated = size * 2;
  }
  shapes[size++] = value;
  return shapes;
}

double rychkov::composition::getArea(const Shape*const* shapes, size_t size) noexcept
{
  double result = 0;
  for (size_t i = 0; i < size; i++)
  {
    result += shapes[i]->getArea();
  }
  return result;
}
rychkov::rectangle_t rychkov::composition::getFrameRect(const Shape*const* shapes, size_t size) noexcept
{
  point_t bottomLeft{0, 0}, topRight{0, 0};
  for (size_t i = 0; i < size; i++)
  {
    rectangle_t tempFrame = shapes[0]->getFrameRect();
    if ((tempFrame.height == 0) || (tempFrame.width == 0))
    {
      continue;
    }

    point_t tempBottomLeft = {tempFrame.pos.x - tempFrame.width / 2, tempFrame.pos.y - tempFrame.height / 2};
    point_t tempTopRight = {tempFrame.pos.x + tempFrame.width / 2, tempFrame.pos.y + tempFrame.height / 2};
    if ((bottomLeft.x == 0) && (bottomLeft.y == 0) && (bottomLeft.x == 0) && (bottomLeft.y == 0))
    {
      bottomLeft = tempBottomLeft;
      topRight = tempTopRight;
    }
    bottomLeft.x = std::min(bottomLeft.x, tempBottomLeft.x);
    bottomLeft.y = std::min(bottomLeft.y, tempBottomLeft.y);
    topRight.x = std::max(topRight.x, tempTopRight.x);
    topRight.y = std::max(topRight.y, tempTopRight.y);
  }
  point_t center = {(bottomLeft.x + topRight.x) / 2, (bottomLeft.y + topRight.y) / 2};
  return {topRight.y - bottomLeft.y, topRight.x - bottomLeft.x, center};
}
void rychkov::composition::move(Shape*const* shapes, size_t size, point_t destination) noexcept
{
  rectangle_t tempFrame = getFrameRect(shapes, size);
  move(shapes, size, destination.x - tempFrame.pos.x, destination.y - tempFrame.pos.y);
}
void rychkov::composition::move(Shape*const* shapes, size_t size, double deltaX, double deltaY) noexcept
{
  for (size_t i = 0; i < size; i++)
  {
    shapes[i]->move(deltaX, deltaY);
  }
}
void rychkov::composition::scale(Shape*const* shapes, size_t size, double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("scale can't be executed with coefficient 0");
  }
  rectangle_t compositionFrame = getFrameRect(shapes, size);
  for (size_t i = 0; i < size; i++)
  {
    scale(shapes[i], coef, compositionFrame.pos);
  }
}

void rychkov::scale(Shape** shapes, size_t size, double coef, point_t scaleCenter)
{
  for (size_t i = 0; i < size; i++)
  {
    scale(shapes[i], coef, scaleCenter);
  }
}
