#include "polygon.hpp"
#include <cmath>
#include <stdexcept>

namespace
{
  bool hasSameVertices(const maslevtsov::point_t* vertices, std::size_t nVertices)
  {
    for (const maslevtsov::point_t* i = vertices; i < vertices + nVertices - 1; ++i)
    {
      for (const maslevtsov::point_t* j = i + 1; j < vertices + nVertices; ++j)
      {
        if (i->x == j->x && i->y == j->y)
        {
          return true;
        }
      }
    }
    return false;
  }

  maslevtsov::point_t* convertArguments(const double* arguments, std::size_t nArguments)
  {
    if (nArguments % 2 != 0 || nArguments < 6)
    {
      throw std::logic_error("incorrect coordinates");
    }
    maslevtsov::point_t* converted = new maslevtsov::point_t[nArguments / 2];
    std::size_t iConverted = 0;
    for (std::size_t i = 1; i < nArguments; i += 2)
    {
      converted[iConverted++] = {arguments[i - 1], arguments[i]};
    }
    return converted;
  }

  void copy(const maslevtsov::point_t* src, std::size_t nVertices, maslevtsov::point_t* dest)
  {
    for (std::size_t i = 0; i < nVertices; ++i)
    {
      dest[i] = src[i];
    }
  }
}

maslevtsov::Polygon::~Polygon()
{
  delete[] vertices_;
}

maslevtsov::Polygon::Polygon(std::size_t nVertices, const point_t* vertices):
  nVertices_(nVertices),
  vertices_(nullptr)
{
  if (nVertices < 3 || hasSameVertices(vertices, nVertices))
  {
    throw std::logic_error("incorrect coordinates");
  }
  vertices_ = new point_t[nVertices_];
  copy(vertices, nVertices_, vertices_);
}

double maslevtsov::Polygon::getArea() const noexcept
{
  double result = 0;
  for (std::size_t i = 0; i < nVertices_ - 1; ++i)
  {
    result += vertices_[i].x * vertices_[i + 1].y - vertices_[i].y * vertices_[i + 1].x;
  }
  result += vertices_[nVertices_ - 1].x * vertices_[0].y - vertices_[nVertices_ - 1].y * vertices_[0].x;
  result *= 0.5;
  return std::abs(result);
}

maslevtsov::rectangle_t maslevtsov::Polygon::getFrameRect() const noexcept
{
  point_t minPnt{vertices_[0].x, vertices_[0].y}, maxPnt = minPnt;
  for (size_t i = 1; i < nVertices_; ++i)
  {
    minPnt = {minPnt.x < vertices_[i].x ? minPnt.x : vertices_[i].x,
             minPnt.y < vertices_[i].y ? minPnt.y : vertices_[i].y};
    maxPnt = {maxPnt.x > vertices_[i].x ? maxPnt.x : vertices_[i].x,
             maxPnt.y > vertices_[i].y ? maxPnt.y : vertices_[i].y};
  }
  rectangle_t frameRect = {maxPnt.x - minPnt.x, maxPnt.y - minPnt.y,
                          {minPnt.x + (frameRect.width) / 2, minPnt.y + (frameRect.height) / 2}};
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

void maslevtsov::Polygon::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid coefficient");
  }
  point_t frameCenter = getFrameRect().pos;
  for (std::size_t i = 0; i < nVertices_; ++i)
  {
    vertices_[i] = {frameCenter.x - (frameCenter.x - vertices_[i].x) * k,
                   frameCenter.y - (frameCenter.y - vertices_[i].y) * k};
  }
}

maslevtsov::Polygon* maslevtsov::makePolygon(const double* arguments, std::size_t nArguments)
{
  point_t* pntArguments = convertArguments(arguments, nArguments);
  Polygon* polygon = nullptr;
  try
  {
    polygon = new Polygon(nArguments / 2, pntArguments);
  }
  catch (const std::bad_alloc &e)
  {
    delete[] pntArguments;
    throw;
  }
  catch (const std::logic_error &e)
  {
    delete[] pntArguments;
    throw;
  }
  delete[] pntArguments;
  return polygon;
}
