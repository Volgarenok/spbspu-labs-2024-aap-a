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

void guseynov::Square::move(point_t pos)
{
  assigment({pos.x - (length_ / 2), pos.y - (length_ / 2)});
}

void guseynov::Square::move(double x, double y)
{
  assigment({leftLowP_.x + x, leftLowP_.y + y});
}

void guseynov::Square::scaleWithoutCheck(double k)
{
  assigment({leftLowP_.x - (length_ * k - length_) / 2, leftLowP_.y - (length_ * k - length_) / 2}, length_ * k);
}

void guseynov::Square::assigment(point_t leftLowP)
{
  leftLowP_ = leftLowP;
  clear(n_);
  createArrayRectangle(leftLowP, length_, n_, 0);
}

void guseynov::Square::assigment(point_t leftLowP, double length)
{
  leftLowP_ = leftLowP;
  length_ = length;
  clear(n_);
  createArrayRectangle(leftLowP, length_, n_, 0);
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

void guseynov::Square::createArrayRectangle(guseynov::point_t lower, double squareLength, const size_t m, size_t n)
{
  if (n == 0)
  {
    rectangleArray_ = new guseynov::Rectangle*[m];
  }
  if (m != n)
  {
    double oneThirdLength = squareLength / 3;
    double twoThirdLength = squareLength * 2 / 3;
    try
    {
      rectangleArray_[n++] = new Rectangle(lower,
      {lower.x + oneThirdLength, lower.y + twoThirdLength});
      rectangleArray_[n++] = new Rectangle({lower.x, lower.y + twoThirdLength},
      {lower.x + twoThirdLength, lower.y + squareLength});
      rectangleArray_[n++] = new Rectangle({lower.x + twoThirdLength, lower.y + oneThirdLength},
      {lower.x + squareLength, lower.y + squareLength});
      rectangleArray_[n++] = new Rectangle({lower.x + oneThirdLength, lower.y},
      {lower.x + squareLength, lower.y + oneThirdLength});
    }
    catch(const std::bad_alloc &)
    {
      clear(n);
      throw;
    }
    createArrayRectangle({lower.x + oneThirdLength, lower.y + oneThirdLength}, oneThirdLength, m, n);
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
