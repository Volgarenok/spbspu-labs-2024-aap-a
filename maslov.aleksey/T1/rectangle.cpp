#include "rectangle.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>

maslov::Rectangle::Rectangle(point_t lowerLeftCorner, point_t upperRightCorner):
  regularArray_(nullptr),
  n_(0),
  nWidth_(0)
{
  if (upperRightCorner.x <= lowerLeftCorner.x || upperRightCorner.y <= lowerLeftCorner.y)
  {
    throw std::invalid_argument("Rectangle has incorrect parameters");
  }
  double length = std::fabs(lowerLeftCorner.x - upperRightCorner.x);
  double width = std::fabs(lowerLeftCorner.y - upperRightCorner.y);
  double w = width;
  double l = length;
  constexpr double error = 0.01;
  while (std::fabs(w) > error)
  {
    double temp = w;
    w = std::fmod(l, w);
    l = temp;
  }
  double square = l;
  size_t nWidth = width / square;
  size_t nLength = length / square;
  size_t total = nWidth * nLength;
  n_ = total;
  if (nWidth > nLength)
  {
    std::swap(nWidth, nLength);
  }
  nWidth_ = nWidth;
  regularArray_ = new Regular*[n_];
  for (size_t i = 0; i < nLength; i++)
  {
    for (size_t j = 0; j < nWidth; j++)
    {
      size_t index = 0;
      if (i % 2 == 0)
      {
        index = i * nWidth + j;
      }
      else
      {
        index = i * nWidth + (nWidth - 1 - j);
      }
      double centerX = lowerLeftCorner.x + j * square + square / 2.0;
      double centerY = lowerLeftCorner.y + (nLength - 1 - i) * square + square / 2.0;
      point_t center = {centerX, centerY};
      point_t inCircle = {center.x, center.y + (square / 2.0)};
      point_t outCircle = {center.x + square / 2.0, center.y + square / 2.0};
      try
      {
        regularArray_[index] = new Regular(center, inCircle, outCircle);
      }
      catch (const std::bad_alloc & e)
      {
        clear(index);
        throw;
      }
    }
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
  double minX = std::numeric_limits<double>::max();
  double minY = std::numeric_limits<double>::max();
  double maxX = std::numeric_limits<double>::lowest();
  double maxY = std::numeric_limits<double>::lowest();
  size_t nLength = n_ / nWidth_;
  for (size_t i = 0; i < nLength; i++)
  {
    for (size_t j = 0; j < nWidth_; j++)
    {
      if (regularArray_[i * 1 + j] != nullptr)
      {
        point_t center = regularArray_[i * 1 + j]->getFrameRect().pos;
        maxX = std::max(maxX, center.x);
        minX = std::min(minX, center.x);
        maxY = std::max(maxY, center.y);
        minY = std::min(minY, center.y);
      }
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
void maslov::Rectangle::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Incorrect scale factor");
  }
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
      regularArray_[index]->scale(k);
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
