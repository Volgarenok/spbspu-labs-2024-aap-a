#include "rectangle.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>

maslov::Rectangle::Rectangle(point_t lowerLeftCorner, point_t upperRightCorner):
  n_(calculateSquares(lowerLeftCorner, upperRightCorner)),
  nWidth_(calculateSquaresOnSides(lowerLeftCorner, upperRightCorner).first),
  regularArray_(createRegularArray(lowerLeftCorner, upperRightCorner))
{
  if (upperRightCorner.x <= lowerLeftCorner.x || upperRightCorner.y <= lowerLeftCorner.y)
  {
    clear(n_);
    throw std::invalid_argument("Rectangle has incorrect parameters");
  }
}
maslov::Rectangle::~Rectangle()
{
  clear(n_);
}
double maslov::Rectangle::getArea() const
{
  return getFrameRect().height * getFrameRect().width;
}
maslov::rectangle_t maslov::Rectangle::getFrameRect() const
{
  double minX = std::numeric_limits< double >::max();
  double minY = std::numeric_limits< double >::max();
  double maxX = std::numeric_limits< double >::lowest();
  double maxY = std::numeric_limits< double >::lowest();
  size_t nLength = n_ / nWidth_;
  for (size_t i = 0; i < nLength; i++)
  {
    for (size_t j = 0; j < nWidth_; j++)
    {
      point_t center = regularArray_[i * 1 + j]->getFrameRect().pos;
      maxX = std::max(maxX, center.x);
      minX = std::min(minX, center.x);
      maxY = std::max(maxY, center.y);
      minY = std::min(minY, center.y);
    }
  }
  double centerX = (minX + maxX) / 2.0;
  double centerY = (minY + maxY) / 2.0;
  double squareSize = regularArray_[0]->getFrameRect().width;
  double width = squareSize * nWidth_;
  double height = squareSize * nLength;
  return {width, height, {centerX, centerY}};
}
void maslov::Rectangle::move(point_t s)
{
  point_t center = getFrameRect().pos;
  double dx = s.x - center.x;
  double dy = s.y - center.y;
  for (size_t i = 0; i < n_; ++i)
  {
    regularArray_[i]->move(dx, dy);
  }
}
void maslov::Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < n_; i++)
  {
    regularArray_[i]->move(dx, dy);
  }
}
void maslov::Rectangle::scaleWithoutCheck(double k)
{
  point_t center = getFrameRect().pos;
  double centerX = center.x;
  double centerY = center.y;
  double squareSize = regularArray_[0]->getFrameRect().width;
  size_t nlength = n_ / nWidth_;
  double startX = centerX - (nlength * squareSize) / 2.0;
  double startY = centerY - (nWidth_ * squareSize) / 2.0;
  for (size_t i = 0; i < nWidth_; i++)
  {
    for (size_t j = 0; j < nlength; j++)
    {
      size_t index = i * nlength + j;
      regularArray_[index]->scaleWithoutCheck(k);
      double offsetX = startX + j * squareSize + squareSize / 2.0;
      double offsetY = startY + i * squareSize + squareSize / 2.0;
      point_t centerRegular = regularArray_[index]->getFrameRect().pos;
      double cRegularX = centerRegular.x;
      double cRegularY = centerRegular.y;
      regularArray_[index]->move(offsetX - cRegularX, offsetY - cRegularY);
    }
  }
}
void maslov::Rectangle::clear(size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete regularArray_[i];
  }
  delete[] regularArray_;
}
maslov::Shape * maslov::Rectangle::clone() const
{
  rectangle_t rectangle = getFrameRect();
  point_t center = rectangle.pos;
  double height = rectangle.height;
  double width = rectangle.width;
  point_t lowerLeft = {center.x - width / 2.0, center.y - height / 2.0};
  point_t upperRight = {center.x + width / 2.0, center.y + height / 2.0};
  return new Rectangle(lowerLeft, upperRight);
}
double maslov::Rectangle::calculateSide(point_t lower, point_t upper)
{
  double length = std::fabs(lower.x - upper.x);
  double width = std::fabs(lower.y - upper.y);
  double w = width;
  double l = length;
  constexpr double error = 0.01;
  while (std::fabs(w) > error)
  {
    double temp = w;
    w = std::fmod(l, w);
    l = temp;
  }
  return l;
}
std::pair<size_t, size_t> maslov::Rectangle::calculateSquaresOnSides(point_t lower,
    point_t upper)
{
  double length = std::fabs(lower.x - upper.x);
  double width = std::fabs(lower.y - upper.y);
  double square = calculateSide(lower, upper);
  size_t nWidth = width / square;
  size_t nLength = length / square;
  if (nWidth > nLength)
  {
    std::swap(nWidth, nLength);
  }
  return std::make_pair(nWidth, nLength);
}
size_t maslov::Rectangle::calculateSquares(point_t lower, point_t upper)
{
  std::pair<size_t, size_t> squaresOnSides = calculateSquaresOnSides(lower, upper);
  size_t total = squaresOnSides.first * squaresOnSides.second;
  return total;
}
maslov::Regular ** maslov::Rectangle::createRegularArray(point_t lower, point_t upper)
{
  size_t nLength = n_ / nWidth_;
  double square = calculateSide(lower, upper);
  Regular ** regularArray = new Regular*[n_];
  for (size_t i = 0; i < nLength; i++)
  {
    for (size_t j = 0; j < nWidth_; j++)
    {
      size_t index = 0;
      if (i % 2 == 0)
      {
        index = i * nWidth_ + j;
      }
      else
      {
        index = i * nWidth_ + (nWidth_ - 1 - j);
      }
      double centerX = lower.x + j * square + square / 2.0;
      double centerY = lower.y + (nLength - 1 - i) * square + square / 2.0;
      point_t center = {centerX, centerY};
      point_t inCircle = {center.x, center.y + (square / 2.0)};
      point_t outCircle = {center.x + square / 2.0, center.y + square / 2.0};
      try
      {
        regularArray[index] = new Regular(center, inCircle, outCircle);
      }
      catch (const std::bad_alloc &)
      {
        clear(index);
        throw;
      }
    }
  }
  return regularArray;
}
