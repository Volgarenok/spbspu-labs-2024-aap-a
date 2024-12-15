#include "polygon.hpp"

maslevtsov::Polygon::~Polygon()
{
  delete[] vertices_;
}

maslevtsov::Polygon::Polygon(std::size_t nVertices, point_t vertices)
{}

double maslevtsov::Polygon::getArea() const noexcept
{}

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
