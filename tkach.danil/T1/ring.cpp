#include "ring.hpp"
#include <cmath>
#include <stdexcept>

namespace
{
  double getDist(const tkach::point_t& point1, const tkach::point_t& point2)
  {
    return std::sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
  }
}

tkach::Ring::Ring(const point_t* in_reg_points, const point_t* out_reg_points):
  in_reg_(nullptr),
  out_reg_(nullptr)
{
  double max_in = std::max(getDist(in_reg_points[0], in_reg_points[1]), getDist(in_reg_points[0], in_reg_points[2]));
  double max_out = std::max(getDist(out_reg_points[0], out_reg_points[1]), getDist(out_reg_points[0], out_reg_points[2]));
  if (max_out < max_in)
  {
    throw std::logic_error("Outer radius is bigger than inner");
  }
  try
  {
    in_reg_ = new tkach::Regular({in_reg_points[0], in_reg_points[1], in_reg_points[2]});
    out_reg_ = new tkach::Regular({out_reg_points[0], out_reg_points[1], out_reg_points[2]});
  }
  catch (const std::logic_error& e)
  {
    delete in_reg_;
    delete out_reg_;
    throw;
  }
  catch (const std::bad_alloc& e)
  {
    delete in_reg_;
    delete out_reg_;
    throw;
  }
}

tkach::Ring::~Ring()
{
  delete in_reg_;
  delete out_reg_;
}

double tkach::Ring::getArea() const
{
  return out_reg_->getArea() - in_reg_->getArea();
}

tkach::rectangle_t tkach::Ring::getFrameRect() const
{
  return out_reg_->getFrameRect();
}

void tkach::Ring::move(const double add_to_x, const double add_to_y)
{
  in_reg_->move(add_to_x, add_to_y);
  out_reg_->move(add_to_x, add_to_y);
}

void tkach::Ring::move(const point_t& point_to_move)
{
  in_reg_->move(point_to_move);
  out_reg_->move(point_to_move);
}

void tkach::Ring::scaleOneOfUniqueShapes(const double multiplier)
{
  in_reg_->scale(multiplier);
  out_reg_->scale(multiplier);
}
