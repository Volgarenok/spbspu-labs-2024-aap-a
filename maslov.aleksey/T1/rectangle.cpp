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
  double length = std::abs(lowerLeftCorner.x - upperRightCorner.x);
  double width = std::abs(lowerLeftCorner.y - upperRightCorner.y);
  double w = width;
  double l = length;
  constexpr double error = 0.01;
  while (std::fabs(w) > error)
  {
    double temp = w;
    w = std::fmod(l, w);
    l = temp;
  }
  size_t N_width = width / l;
  size_t N_length = length / l;
  size_t Total = N_width * N_length;
  n_ = Total;
  if (N_width > N_length)
  {
    std::swap(N_width, N_length);
  }
  nWidth_ = N_width;
  regularArray_ = new Regular*[n_];
  for (size_t i = 0; i < N_length; i++)
  {
    for (size_t j = 0; j < N_width; j++)
    {
      size_t index = (i % 2 == 0) ? (i * N_width + j) : (i * N_width + (N_width - 1 - j));
      try
      {
        point_t center = {lowerLeftCorner.x + j * l + l / 2, lowerLeftCorner.y + (N_length - 1 - i) * l + l / 2};
        point_t inCircle = { center.x, center.y + (l / 2) };
        point_t outCircle = { center.x + l / 2, center.y + l / 2 };
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
  for (size_t i = 0; i < n_ / nWidth_; i++)
  {
    for (size_t j = 0; j < nWidth_; j++)
    {
      if (regularArray_[i * 1 + j] != nullptr)
      {
        point_t center = regularArray_[i * 1 + j]->getFrameRect().pos;
        if (center.x < minX) minX = center.x;
        if (center.y < minY) minY = center.y;
        if (center.x > maxX) maxX = center.x;
        if (center.y > maxY) maxY = center.y;
      }
    }
  }
  double width = regularArray_[0]->getFrameRect().width * nWidth_;
  double height = n_ / nWidth_ * regularArray_[0]->getFrameRect().width;
  point_t center = {(minX + maxX) / 2.0, (minY + maxY) / 2.0 };
  return {width, height, {center}};
}
void maslov::Rectangle::move(point_t s)
{
  point_t currentCenter = getFrameRect().pos;
  double dx = s.x - currentCenter.x;
  double dy = s.y - currentCenter.y;
  for (size_t i = 0; i < n_; ++i) {
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
  double scaleFactor = k;
  for (size_t i = 0; i < n_; i++)
  {
    regularArray_[i]->scale(scaleFactor);
  }
  double squareSize = regularArray_[0]->getFrameRect().height;
  int width = n_ / nWidth_;
  int length = nWidth_;
  double startX = centerX - (width * squareSize) / 2;
  double startY = centerY - (length * squareSize) / 2;
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < width; j++)
    {
      size_t index = i * width + j;
      double offsetX = startX + j * squareSize + squareSize / 2;
      double offsetY = startY + i * squareSize + squareSize / 2;
      regularArray_[index]->move(offsetX - regularArray_[index]->getFrameRect().pos.x,
        offsetY - regularArray_[index]->getFrameRect().pos.y);
    }
  }
}
void maslov::Rectangle::clear(size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete regularArray_[i];
  }
}
