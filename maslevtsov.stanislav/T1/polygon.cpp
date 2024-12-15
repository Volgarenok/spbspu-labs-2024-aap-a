#include "polygon.hpp"
#include <cmath>

maslevtsov::Polygon::~Polygon()
{
  delete[] vertices_;
}

maslevtsov::Polygon::Polygon(std::size_t nVertices, point_t* vertices):
  nVertices_(nVertices),
  vertices_(vertices)
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
{}

void maslevtsov::Polygon::move(point_t pnt) noexcept
{}

void maslevtsov::Polygon::move(double dx, double dy) noexcept
{}

void maslevtsov::Polygon::scale(double k) noexcept
{}

maslevtsov::Polygon* maslevtsov::makePolygon(const double* arguments)
{}
