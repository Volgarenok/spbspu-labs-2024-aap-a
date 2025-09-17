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
  if (n_ == 0)
    return {0, 0, {0, 0}};
  rectangle_t firstRect = rectangleArray_[0]->getFrameRect();
  double minX = firstRect.pos.x - firstRect.width / 2;
  double maxX = firstRect.pos.x + firstRect.width / 2;
  double minY = firstRect.pos.y - firstRect.height / 2;
  double maxY = firstRect.pos.y + firstRect.height / 2;
  for (size_t i = 1; i < n_; i++)
  {
    if (rectangleArray_[i] != nullptr)
    {
      rectangle_t rect = rectangleArray_[i]->getFrameRect();
      double rectMinX = rect.pos.x - rect.width / 2;
      double rectMaxX = rect.pos.x + rect.width / 2;
      double rectMinY = rect.pos.y - rect.height / 2;
      double rectMaxY = rect.pos.y + rect.height / 2;
      minX = std::min(minX, rectMinX);
      maxX = std::max(maxX, rectMaxX);
      minY = std::min(minY, rectMinY);
      maxY = std::max(maxY, rectMaxY);
    }
  }
  return {maxX - minX, maxY - minY, {(minX + maxX) / 2, (minY + maxY) / 2}};
}

void guseynov::Square::move(point_t newPos)
{
  if (n_ == 0 || rectangleArray_[0] == nullptr)
    return;
  rectangle_t currentFrame = getFrameRect();
  double dx = newPos.x - currentFrame.pos.x;
  double dy = newPos.y - currentFrame.pos.y;
  for (size_t i = 0; i < n_; i++)
  {
    if (rectangleArray_[i] != nullptr)
    {
      rectangleArray_[i]->move(dx, dy);
    }
  }
  leftLowP_.x += dx;
  leftLowP_.y += dy;
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
  leftLowP_.x += dx;
  leftLowP_.y += dy;
}

void guseynov::Square::scaleWithoutCheck(double k)
{
  if (n_ == 0 || rectangleArray_[0] == nullptr)
    return;
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < n_; i++)
  {
    if (rectangleArray_[i] != nullptr)
    {
      point_t currentPos = rectangleArray_[i]->getFrameRect().pos;
      double dx = currentPos.x - center.x;
      double dy = currentPos.y - center.y;
      dx *= k;
      dy *= k;
      point_t newPos = {center.x + dx, center.y + dy};
      rectangleArray_[i]->scale(k);
      rectangleArray_[i]->move(newPos);
    }
  }
  length_ *= k;
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
