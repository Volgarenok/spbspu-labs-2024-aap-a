#include "composite-shape.hpp"
#include <stdexcept> 
#include <lrgcpy.hpp>

savintsev::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < amt_; ++i)
  {
    delete lst_[i];
  }
  delete lst_;
}

savintsev::CompositeShape::CompositeShape(size_t n):
  lst_(nullptr),
  amt_(0),
  cap_(n)
{
  lst_ = new Shape * [cap_];
}

savintsev::CompositeShape::CompositeShape(): CompositeShape(1)
{}

void savintsev::CompositeShape::push_back(Shape * shp)
{
  lst_[amt_++] = shp;
  if (amt_ == cap_)
  {
    Shape ** new_lst = createAmpCopy(lst_, cap_, cap_ + cap_);
    for (size_t i = 0; i < amt_; ++i)
    {
      delete lst_[i];
    }
    delete lst_;
    lst_ = new_lst;
    cap_ += cap_;
  }
}

savintsev::Shape * savintsev::CompositeShape::at(size_t id)
{
  if (id >= amt_)
  {
    throw std::out_of_range("ERROR: Out of range");
  }
  return lst_[id];
}

savintsev::Shape * savintsev::CompositeShape::at(size_t id) const
{
  if (id >= amt_)
  {
    throw std::out_of_range("ERROR: Out of range");
  }
  return lst_[id];
}
