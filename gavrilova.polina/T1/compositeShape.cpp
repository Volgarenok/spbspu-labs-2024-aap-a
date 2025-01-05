#include "compositeShape.hpp"
#include <algorithm>

gavrilova::CompositeShape::CompositeShape():
  size_(0),
  capacity_(10), 
  shapes_(nullptr)
{
  shapes_ = new Shape*[capacity_]; 
}

gavrilova::CompositeShape::~CompositeShape() {
  for (size_t i = 0; i < size_; ++i) {
    delete shapes_[i];
  }
  delete[] shapes_;
}
gavrilova::CompositeShape::CompositeShape(size_t capacity):
  CompositeShape()
{
  resize(capacity);
}
gavrilova::CompositeShape::CompositeShape(const CompositeShape& other):
  CompositeShape(other.capacity_)
{
  size_ = other.size_;
  for (size_t i = 0; i < size_; ++i) {
    shapes_[i] = other.shapes_[i]->clone(); 
  }
}

gavrilova::CompositeShape& gavrilova::CompositeShape::operator=(const CompositeShape& other) {
  CompositeShape cpy(other);
  swap(cpy);
  return *this;
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

gavrilova::CompositeShape& gavrilova::CompositeShape::operator=(CompositeShape&& other) noexcept {
  if (this != &other) {
    swap(other);
    for (size_t i = 0; i < other.size_; ++i) {
      delete other.shapes_[i];
    }
    other.size_ = 0;
    other.capacity_ = 0;
    other.shapes_ = nullptr;
  }
  return *this;
}

void gavrilova::CompositeShape::push_back(Shape* shp) {
  if (!shp) {
    throw std::invalid_argument("Shape cannot be null");
  }
  if (size_ == capacity_) {
    resize(capacity_ * 2);
  }
  shapes_[size_++] = shp;
}

void gavrilova::CompositeShape::pop_back() {
  if (size_ == 0) {
    throw std::out_of_range("No shape to pop");
  }
  delete shapes_[--size_];
}

gavrilova::Shape* gavrilova::CompositeShape::at(size_t id) const {
  if (id >= size_) {
      throw std::out_of_range("Index out of range");
  }
  return shapes_[id];
}

gavrilova::Shape* gavrilova::CompositeShape::operator[](size_t id) {
  return shapes_[id];
}


bool gavrilova::CompositeShape::empty() const noexcept {
  return size_ == 0;
}

size_t gavrilova::CompositeShape::size() const noexcept {
  return size_;
}

void gavrilova::CompositeShape::scale(double k) {
  for (size_t i = 0; i < size_; ++i) {
    shapes_[i]->scale(k);
  }
}

void gavrilova::CompositeShape::move(double difX, double difY) {
  for (size_t i = 0; i < size_; ++i) {
    shapes_[i]->move(difX, difY);
  }
}

gavrilova::rectangle_t gavrilova::CompositeShape::getFrameRect() const {
  if (size_ == 0) {
    return {0, 0, {0, 0}};
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

void gavrilova::CompositeShape::resize(size_t new_capacity) {
  Shape** new_shapes = new Shape*[new_capacity];

  for (size_t i = 0; i < size_; ++i) {
    new_shapes[i] = shapes_[i];
  }

  delete[] shapes_;
  shapes_ = new_shapes;
  capacity_ = new_capacity;
}
void gavrilova::CompositeShape::swap(CompositeShape& rhs) noexcept{
  std::swap(size_, rhs.size_);
  std::swap(capacity_, rhs.capacity_);
  std::swap(shapes_, rhs.shapes_);
}
