#include "compositeShape.hpp"
#include "shapeManip.hpp"

gavrilova::CompositeShape::CompositeShape():
  CompositeShape(1)
{}

gavrilova::CompositeShape::CompositeShape(size_t capacity):
  size_(0),
  capacity_(capacity),
  shapes_(new Shape*[capacity_])
{}

gavrilova::CompositeShape::CompositeShape(const CompositeShape& other):
  size_(other.size_),
  capacity_(other.capacity_),
  shapes_(new Shape*[capacity_])
{
  size_t cur_size = 0;
  for (size_t i = 0; i < size_; ++i) {
    try {
      shapes_[i] = other.shapes_[i]->clone();
      ++cur_size;
    } catch (const std::bad_alloc&) {
      size_ = cur_size;
      clear();
      throw;
    }
  }
}

gavrilova::CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
  size_(other.size_),
  capacity_(other.capacity_),
  shapes_(other.shapes_)
{
  other.size_ = 0;
  other.capacity_ = 0;
  other.shapes_ = nullptr;
}

gavrilova::CompositeShape::~CompositeShape()
{
  clear();
}


gavrilova::CompositeShape& gavrilova::CompositeShape::operator=(const CompositeShape& other)
{
  if (this != std::addressof(other)) {
    CompositeShape cpy(other);
    swap(cpy);
  }
  return *this;
}

gavrilova::CompositeShape& gavrilova::CompositeShape::operator=(CompositeShape&& other) noexcept
{
  if (this != std::addressof(other)) {
    swap(other);
    other.clear();
  }
  return *this;
}

void gavrilova::CompositeShape::push_back(Shape* shp)
{
  if (!shp) {
    throw std::invalid_argument("Shape cannot be null");
  }
  expand();
  shapes_[size_++] = shp;
}

void gavrilova::CompositeShape::pop_back()
{
  if (size_ == 0) {
    throw std::out_of_range("No shape to pop");
  }
  delete shapes_[--size_];
}

gavrilova::Shape* gavrilova::CompositeShape::operator[](size_t id) noexcept
{
  return shapes_[id];
}

const gavrilova::Shape* gavrilova::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}

gavrilova::Shape* gavrilova::CompositeShape::at(size_t id)
{
  if (id >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return shapes_[id];
}

const gavrilova::Shape* gavrilova::CompositeShape::at(size_t id) const
{
  if (id >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return shapes_[id];
}

bool gavrilova::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}

size_t gavrilova::CompositeShape::size() const noexcept
{
  return size_;
}

void gavrilova::CompositeShape::scale(double k)
{
  if (k <= 0) {
    throw std::logic_error("Коэффицент должен быть положительным");
  }
  point_t pos = getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i) {
    scaleShapeWithoutCheck(*shapes_[i], pos, k);
  }
}

void gavrilova::CompositeShape::move(const point_t& p) noexcept
{
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}

void gavrilova::CompositeShape::move(double difX, double difY) noexcept
{
  for (size_t i = 0; i < size_; ++i) {
    shapes_[i]->move(difX, difY);
  }
}

gavrilova::rectangle_t gavrilova::CompositeShape::getFrameRect() const
{
  if (empty()) {
    throw std::logic_error("Composite shape is empty.");
  }

  double minX = shapes_[0]->getFrameRect().pos.x - shapes_[0]->getFrameRect().width / 2;
  double maxX = shapes_[0]->getFrameRect().pos.x + shapes_[0]->getFrameRect().width / 2;
  double minY = shapes_[0]->getFrameRect().pos.y - shapes_[0]->getFrameRect().height / 2;
  double maxY = shapes_[0]->getFrameRect().pos.y + shapes_[0]->getFrameRect().height / 2;

  for (size_t i = 1; i < size_; ++i) {
    auto rect = shapes_[i]->getFrameRect();
    minX = std::min(minX, rect.pos.x - rect.width / 2);
    maxX = std::max(maxX, rect.pos.x + rect.width / 2);
    minY = std::min(minY, rect.pos.y - rect.height / 2);
    maxY = std::max(maxY, rect.pos.y + rect.height / 2);
  }

  rectangle_t frameRect = {
    maxX - minX,
    maxY - minY,
    {minX + (maxX - minX) / 2, minY + (maxY - minY) / 2}
  };
  return frameRect;
}

double gavrilova::CompositeShape::getArea() const noexcept
{
  double area = 0;
  for (size_t i = 0; i < size_; ++i) {
    area += shapes_[i]->getArea();
  }
  return area;
}

void gavrilova::CompositeShape::expand()
{
  if (size_ < capacity_) {
    return;
  }
  const int CONSTANTA_FOR_RESIZE = 10;
  resize(capacity_ + CONSTANTA_FOR_RESIZE);
}

void gavrilova::CompositeShape::resize(size_t new_capacity)
{
  Shape** new_shapes = new Shape*[new_capacity];
  for (size_t i = 0; i < size_; ++i) {
    new_shapes[i] = shapes_[i];
  }
  delete[] shapes_;
  shapes_ = new_shapes;
  capacity_ = new_capacity;
}

void gavrilova::CompositeShape::swap(CompositeShape& rhs) noexcept
{
  std::swap(size_, rhs.size_);
  std::swap(capacity_, rhs.capacity_);
  std::swap(shapes_, rhs.shapes_);
}

void gavrilova::CompositeShape::clear() noexcept
{
  for (size_t i = 0; i < size_; ++i) {
    delete shapes_[i];
  }
  delete[] shapes_;
  size_ = 0;
  capacity_ = 0;
}

