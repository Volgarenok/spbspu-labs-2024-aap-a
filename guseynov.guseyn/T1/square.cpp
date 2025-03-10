#include "square.hpp"

#include <stdexcept>
#include <cmath>

guseynov::Square::Square(point_t leftLowP, double length):
  n_{determinateNum(length)},
  rectangleArray_{createArrayRectangle(leftLowP, length)}
{
  if (length <= 0)
  {
    throw std::invalid_argument("Error in SQUARE parameters");
  }
}

guseynov::Square::~Square()
{
  clear(n_);
}

double guseynov::Square::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < n_; i++)
  {
    area += rectangleArray_[i]->getArea();
  }
  return area;
}

guseynov::rectangle_t guseynov::Square::getFrameRect() const
{
  double length = std::sqrt(guseynov::Square::getArea());
  point_t leftLowP = rectangleArray_[0]->getFrameRect().pos;
  return {length, length, {leftLowP.x + (length / 2), leftLowP.y + (length / 2)}};
}

void guseynov::Square::move(point_t pos)
{
  double length = std::sqrt(guseynov::Square::getArea());
  assigment({pos.x - (length / 2), pos.y - (length / 2)});
}

void guseynov::Square::move(double x, double y)
{
  point_t leftLowP = rectangleArray_[0]->getFrameRect().pos;
  assigment({leftLowP.x + x, leftLowP.y + y});
}

void guseynov::Square::scaleWithoutCheck(double k)
{
  double length = std::sqrt(guseynov::Square::getArea());
  point_t leftLowP = rectangleArray_[0]->getFrameRect().pos;
  assigmentPlusLength({leftLowP.x - (length * k - length) / 2, leftLowP.y - (length * k - length) / 2}, length * k);
}

void guseynov::Square::assigment(point_t leftLowP)
{
  double length = std::sqrt(guseynov::Square::getArea());
  clear(n_);
  rectangleArray_ = createArrayRectangle(leftLowP, length);
}

void guseynov::Square::assigmentPlusLength(point_t leftLowP, double length)
{
  clear(n_);
  rectangleArray_ = createArrayRectangle(leftLowP, length);
}

guseynov::Shape * guseynov::Square::clone() const
{
  double length = std::sqrt(guseynov::Square::getArea());
  point_t leftLowP = rectangleArray_[0]->getFrameRect().pos;
  return new Square(leftLowP, length);
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

guseynov::Rectangle ** guseynov::Square::createArrayRectangle(guseynov::point_t lower, double squareLength)
{
  static size_t n = 0;
  static guseynov::Rectangle ** rectangleArray;
  if (n == 0)
  {
    rectangleArray = new guseynov::Rectangle*[n_];
  }
  if (n_ != n)
  {
    double oneThirdLength = squareLength / 3;
    double twoThirdLength = squareLength * 2 / 3;
    try
    {
      rectangleArray[n++] = new Rectangle(lower, {lower.x + oneThirdLength, lower.y + twoThirdLength});
      rectangleArray[n++] = new Rectangle({lower.x, lower.y + twoThirdLength}, {lower.x + twoThirdLength, lower.y + squareLength});
      rectangleArray[n++] = new Rectangle({lower.x + twoThirdLength, lower.y + oneThirdLength}, {lower.x + squareLength, lower.y + squareLength});
      rectangleArray[n++] = new Rectangle({lower.x + oneThirdLength, lower.y}, {lower.x + squareLength, lower.y + oneThirdLength});
    }
    catch(const std::bad_alloc &)
    {
      clear(n);
      throw;
    }
    createArrayRectangle({lower.x + oneThirdLength, lower.y + oneThirdLength}, oneThirdLength);
  }
  return rectangleArray;
}

void guseynov::Square::clear(size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete rectangleArray_[i];
  }
  delete[] rectangleArray_;
}
