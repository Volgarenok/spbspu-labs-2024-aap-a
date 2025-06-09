#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "triangle.hpp"

komarova::Rectangle::Rectangle(point_t low_left, point_t up_right):
  triangles_(initialiseTriangles(low_left, up_right))
{}
komarova::Rectangle::~Rectangle()
{
  clear();
}
double komarova::Rectangle::getArea() const
{
  return triangles_[0]->getArea() * 8;
}
komarova::rectangle_t komarova::Rectangle::getFrameRect() const
{
  rectangle_t tmp = triangles_[0]->getFrameRect();
  double width = tmp.width * 2;
  double height = tmp.height * 2;
  point_t pos = { (tmp.pos.x - tmp.width / 2.0), (tmp.pos.y - tmp.height / 2.0) };
  return { width, height, pos };
}
void komarova::Rectangle::move(point_t point)
{
  for (size_t i = 0; i < cnt_trg; i++)
  {
    triangles_[i]->move(point);
  }
}
void komarova::Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < cnt_trg; i++)
  {
    triangles_[i]->move(dx, dy);
  }
}
void komarova::Rectangle::scaleUnsafe(double coef)
{
  for (size_t i = 0; i < cnt_trg; i++)
  {
    triangles_[i]->scale(coef);
  }
}
void komarova::Rectangle::clear()
{
  clear(cnt_trg);
}
void komarova::Rectangle::clear(size_t cnt)
{
  for (size_t i = 0; i < cnt; i++)
  {
    delete triangles_[i];
  }
  delete[] triangles_;
}
komarova::Shape** komarova::Rectangle::initialiseTriangles(point_t low_left, point_t up_right)
{
  Shape** triangles = new Shape*[cnt_trg]();
  size_t trg_now = 0;
  try
  {
    if (low_left.x >= up_right.x || low_left.y >= up_right.y)
    {
      throw std::logic_error("incorrect coordinates");
    }
    double width = up_right.x - low_left.x;
    double height = up_right.y - low_left.y;
    point_t up_left = { low_left.x, up_right.y };
    point_t low_right = { up_right.x, low_left.y };
    point_t center = { (low_left.x + width / 2.0), (low_left.y + height / 2.0) };
    triangles[0] = new Triangle(up_right, center, { up_right.x - width / 2.0, up_right.y });
    trg_now++;
    triangles[1] = new Triangle(up_left, center, { up_right.x - width / 2.0, up_right.y });
    trg_now++;
    triangles[2] = new Triangle(up_left, center, { low_left.x, low_left.y + height / 2.0 });
    trg_now++;
    triangles[3] = new Triangle(low_left, center, { low_left.x, low_left.y + height / 2.0 });
    trg_now++;
    triangles[4] = new Triangle(low_left, center, { low_left.x + width / 2.0, low_left.y });
    trg_now++;
    triangles[5] = new Triangle(low_right, center, { low_left.x + width / 2.0, low_left.y });
    trg_now++;
    triangles[6] = new Triangle(low_right, center, { low_right.x, low_right.y + height / 2.0 });
    trg_now++;
    triangles[7] = new Triangle(up_right, center, { low_right.x, low_right.y + height / 2.0 });
    trg_now++;
    return triangles;
  }
  catch(const std::exception& e)
  {
    for (size_t i = 0; i < trg_now; i++)
    {
      delete triangles_[i];
    }
    delete[] triangles;
    throw;
  }
}
