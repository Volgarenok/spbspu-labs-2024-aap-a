#include "polygon.hpp"
#include <cmath>

maslevtsov::Polygon::~Polygon()
{
  delete[] vertices_;
}

maslevtsov::Polygon::Polygon(std::size_t nVertices, point_t* vertices): nVertices_(nVertices), vertices_(vertices)
{
  if (nVertices < 3)
  {
    throw std::logic_error("incorrect coordinates");
  }
}

double maslevtsov::Polygon::getArea() const noexcept
{
  double result = 0;
  for (std::size_t i = 0; i < nVertices_; ++i)
  {
    result += vertices_[i].x * vertices_[i + 1].y - vertices_[i].y * vertices_[i + 1].x;
  }
  result *= 0.5;
  return std::abs(result);
}

maslevtsov::rectangle_t maslevtsov::Polygon::getFrameRect() const noexcept
{
  rectangle_t frameRect;
  point_t minPnt{vertices_[0].x, vertices_[0].y}, maxPnt = minPnt;
  for (size_t i = 1; i < nVertices_; ++i)
  {
    minPnt = {
      minPnt.x < vertices_[i].x ? minPnt.x : vertices_[i].x, minPnt.y < vertices_[i].y ? minPnt.y : vertices_[i].y};
    maxPnt = {
      minPnt.x > vertices_[i].x ? minPnt.x : vertices_[i].x, minPnt.y > vertices_[i].y ? minPnt.y : vertices_[i].y};
  }
  frameRect.width = maxPnt.x - minPnt.x;
  frameRect.height = maxPnt.y - minPnt.y;
  frameRect.pos.x = minPnt.x + (frameRect.width) / 2;
  frameRect.pos.y = minPnt.y + (frameRect.height) / 2;
  return frameRect;
}

void maslevtsov::Polygon::move(point_t pnt) noexcept
{
  double movedX = pnt.x - getFrameRect().pos.x;
  double movedY = pnt.y - getFrameRect().pos.y;
  for (std::size_t i = 0; i < nVertices_; ++i)
  {
    vertices_[i] = {vertices_[i].x + movedX, vertices_[i].y + movedY};
  }
}

void maslevtsov::Polygon::move(double dx, double dy) noexcept
{
  for (std::size_t i = 0; i < nVertices_; ++i)
  {
    vertices_[i] = {vertices_[i].x + dx, vertices_[i].y + dy};
  }
}

void maslevtsov::Polygon::scale(double k) noexcept
{
  point_t frameCenter = getFrameRect().pos;
  for (std::size_t i = 0; i < nVertices_; ++i)
  {
    vertices_[i] = {
      frameCenter.x - (frameCenter.x - vertices_[i].x) * k, frameCenter.y - (frameCenter.y - vertices_[i].y) * k};
  }
}

maslevtsov::Polygon* maslevtsov::makePolygon(const double* arguments)
{}
