#include "composite-shape.hpp"

maslov::CompositeShape::CompositeShape():
  size_(0)
{}
maslov::CompositeShape::CompositeShape(const CompositeShape & rhs)
{}
maslov::CompositeShape::CompositeShape(CompositeShape && rhs)
{}
maslov::CompositeShape & maslov::CompositeShape::operator=(const CompositeShape & rhs)
{}
maslov::CompositeShape & maslov::CompositeShape::operator=(CompositeShape && rhs)
{}
maslov::CompositeShape::~CompositeShape()
{}
void maslov::CompositeShape::push_back(Shape * shp)
{}
void maslov::CompositeShape::pop_back()
{}
maslov::Shape * maslov::CompositeShape::at(size_t id)
{}
maslov::Shape * maslov::CompositeShape::operator[](size_t id)
{}
bool maslov::CompositeShape::empty()
{}
size_t maslov::CompositeShape::size()
{}
double maslov::CompositeShape::getArea() const
{}
maslov::rectangle_t maslov::CompositeShape::getFrameRect() const
{}
void maslov::CompositeShape::move(point_t s)
{}
void maslov::CompositeShape::move(double dx, double dy)
{}
void maslov::CompositeShape::scale(double k)
{}