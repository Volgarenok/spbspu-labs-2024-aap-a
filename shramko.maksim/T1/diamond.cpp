#include "diamond.hpp"
#include "triangle.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

namespace shramko
{
  point_t Diamond::midpoint(const point_t& a, const point_t& b) const
  {
    return { (a.x + b.x) / 2, (a.y + b.y) / 2 };
  }

  Diamond::Diamond(point_t one, point_t two, point_t three)
  {
    center_ = midpoint(one, two);
    point_t four = {2 * center_.x - three.x, 2 * center_.y - three.y};

    point_t diag1_vec = {two.x - one.x, two.y - one.y};
    point_t diag2_vec = {four.x - three.x, four.y - three.y};

    double dot = diag1_vec.x * diag2_vec.x + diag1_vec.y * diag2_vec.y;

    if (std::abs(dot) > 1e-6)
    {
      throw std::invalid_argument("invalid diamond");
    }

    vertices_[0] = one;
    vertices_[1] = two;
    vertices_[2] = three;
    vertices_[3] = four;

    triangles_ = new Triangle*[TRIANGLE_COUNT];
    try
    {
      point_t midAB = midpoint(one, two);
      point_t midBC = midpoint(two, three);
      point_t midCD = midpoint(three, four);
      point_t midDA = midpoint(four, one);

      triangles_[0] = new Triangle(one, midAB, center_);
      triangles_[1] = new Triangle(midAB, two, center_);
      triangles_[2] = new Triangle(two, midBC, center_);
      triangles_[3] = new Triangle(midBC, three, center_);
      triangles_[4] = new Triangle(three, midCD, center_);
      triangles_[5] = new Triangle(midCD, four, center_);
      triangles_[6] = new Triangle(four, midDA, center_);
      triangles_[7] = new Triangle(midDA, one, center_);
    }
    catch (...)
    {
      for (size_t j = 0; j < TRIANGLE_COUNT; ++j)
      {
        delete triangles_[j];
      }
      delete[] triangles_;
      throw;
    }
  }

  Diamond::~Diamond()
  {
    for (size_t i = 0; i < TRIANGLE_COUNT; ++i)
    {
      delete triangles_[i];
    }
    delete[] triangles_;
  }

  double Diamond::getArea() const
  {
    double area = 0.0;
    for (size_t i = 0; i < TRIANGLE_COUNT; ++i)
    {
      area += triangles_[i]->getArea();
    }
    return area;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    double x_min = vertices_[0].x;
    double x_max = vertices_[0].x;
    double y_min = vertices_[0].y;
    double y_max = vertices_[0].y;

    for (size_t i = 1; i < 4; ++i)
    {
      x_min = std::min(x_min, vertices_[i].x);
      x_max = std::max(x_max, vertices_[i].x);
      y_min = std::min(y_min, vertices_[i].y);
      y_max = std::max(y_max, vertices_[i].y);
    }

    return { x_max - x_min, y_max - y_min, { (x_min + x_max) / 2, (y_min + y_max) / 2 } };
  }

  void Diamond::move(double x, double y)
  {
    for (size_t i = 0; i < TRIANGLE_COUNT; ++i)
    {
      triangles_[i]->move(x, y);
    }
    center_.x += x;
    center_.y += y;
    for (size_t i = 0; i < 4; ++i)
    {
      vertices_[i].x += x;
      vertices_[i].y += y;
    }
  }

  void Diamond::doScale(double k)
  {
    const point_t center = center_;
    for (size_t i = 0; i < 4; ++i)
    {
      vertices_[i].x = center.x + (vertices_[i].x - center.x) * k;
      vertices_[i].y = center.y + (vertices_[i].y - center.y) * k;
    }

    for (size_t i = 0; i < TRIANGLE_COUNT; ++i)
    {
      delete triangles_[i];
    }

    point_t one = vertices_[0];
    point_t two = vertices_[1];
    point_t three = vertices_[2];
    point_t four = vertices_[3];

    point_t midAB = midpoint(one, two);
    point_t midBC = midpoint(two, three);
    point_t midCD = midpoint(three, four);
    point_t midDA = midpoint(four, one);

    triangles_[0] = new Triangle(one, midAB, center);
    triangles_[1] = new Triangle(midAB, two, center);
    triangles_[2] = new Triangle(two, midBC, center);
    triangles_[3] = new Triangle(midBC, three, center);
    triangles_[4] = new Triangle(three, midCD, center);
    triangles_[5] = new Triangle(midCD, four, center);
    triangles_[6] = new Triangle(four, midDA, center);
    triangles_[7] = new Triangle(midDA, one, center);
  }
}
