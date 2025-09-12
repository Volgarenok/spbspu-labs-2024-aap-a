#include "square.hpp"

#include <stdexcept>
#include <cmath>

guseynov::Square::Square(point_t leftLowP, double length):
  leftLowP_(leftLowP),
  n_{determinateNum(length)}
{
  if (length <= 0)
  {
    throw std::invalid_argument("Error in SQUARE parameters");
  }
  createArrayRectangle(leftLowP, length, n_, 0);
  length_ = rectangleArray_[0]->getFrameRect().width * 3;
}

guseynov::Square::~Square()
{
  clear(n_);
}

double guseynov::Square::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < n_; i++)
  {
    area += rectangleArray_[i]->getArea();
  }
  return area;
}

guseynov::rectangle_t guseynov::Square::getFrameRect() const
{
  return {length_, length_, {leftLowP_.x + (length_ / 2), leftLowP_.y + (length_ / 2)}};
}

void guseynov::Square::move(double dx, double dy)
{
  for (size_t i = 0; i < n_; i++)
  {
    if (rectangleArray_[i] != nullptr)
    {
      rectangleArray_[i]->move(dx, dy);
    }
  }
}

void guseynov::Square::move(const point_t& newPos)
{
  if (n_ == 0 || rectangleArray_[0] == nullptr)
    return;
  point_t currentPos = rectangleArray_[0]->getFrameRect().pos;
  double dx = newPos.x - currentPos.x;
  double dy = newPos.y - currentPos.y;
  move(dx, dy);
}

void guseynov::Square::scaleWithoutCheck(double coefficient)
{
  point_t center = rectangleArray_[0]->getFrameRect().pos;
  for (size_t i = 0; i < n_; i++)
  {
    rectangleArray_[i]->scale(coefficient);
    point_t currentPos = rectangleArray_[i]->getFrameRect().pos;
    double dx = (currentPos.x - center.x) * coefficient;
    double dy = (currentPos.y - center.y) * coefficient;
    rectangleArray_[i]->move({center.x + dx, center.y + dy});
  }
}

guseynov::Shape * guseynov::Square::clone() const
{
  return new Square(leftLowP_, length_);
}

size_t guseynov::Square::determinateNum(double squareLength)
{
  size_t n = 0;
  while(squareLength * squareLength > 0.01)
  {
    n += 4;
    squareLength = squareLength / 3;
  }
  return n;
}

void guseynov::Square::createArrayRectangle(point_t lower, double squareLength, size_t m, size_t n)
{
  if (n == 0)
  {
    rectangleArray_ = new Rectangle*[m];
  }
  if (m != n)
  {
    double oneThirdLength = squareLength / 3;
    double twoThirdLength = squareLength * 2 / 3;
    double Length1X = lower.x + squareLength;
    double Length2X = lower.x + twoThirdLength;
    double Length3X = lower.x + oneThirdLength;
    double Length1Y = lower.y + squareLength;
    double Length2Y = lower.y + twoThirdLength;
    double Length3Y = lower.y + oneThirdLength;
    try
    {
      rectangleArray_[n++] = new Rectangle(lower, {Length3X, Length2Y});
      rectangleArray_[n++] = new Rectangle({lower.x, Length2Y}, {Length2X, Length1Y});
      rectangleArray_[n++] = new Rectangle({Length2X, Length3Y}, {Length1X, Length1Y});
      rectangleArray_[n++] = new Rectangle({Length3X, lower.y}, {Length1X, Length3Y});
    }
    catch(const std::bad_alloc &)
    {
      clear(n);
      throw;
    }
    createArrayRectangle({Length3X, Length3Y}, oneThirdLength, m, n);
  }
}

void guseynov::Square::clear(size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete rectangleArray_[i];
  }
  delete[] rectangleArray_;
}
