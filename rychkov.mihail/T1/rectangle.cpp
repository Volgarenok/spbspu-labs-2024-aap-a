#include "rectangle.hpp"

#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <math.hpp>

namespace rychkov
{
  static const Regular emptyHexagon{{0, 0}, {0, 1}, {1 * std::tan(PI / 6), 1}};
}

rychkov::Rectangle::Rectangle(point_t bottomLeft, point_t topRight):
  bottomLeft_(emptyHexagon),
  localHeight_(0),
  localWidth_(0)
{
  if ((topRight.x <= bottomLeft.x) || (topRight.y <= bottomLeft.y))
  {
    throw std::invalid_argument("rectangle vertexes don't match their coordinates");
  }
  double width = topRight.x - bottomLeft.x;
  double height = topRight.y - bottomLeft.y;
  double sideForVerticalHexagon = tryLocalRotation(height, width, 0);
  double sideForHorizontalHexagon = tryLocalRotation(width, height, sideForVerticalHexagon);
  if ((sideForHorizontalHexagon == 0) && (sideForVerticalHexagon == 0))
  {
    throw std::runtime_error("rectangle precision wasn't reached");
  }
  if (sideForHorizontalHexagon > sideForVerticalHexagon)
  {
    bottomLeft_ = generateBasisHexagon(bottomLeft, sideForHorizontalHexagon, true);
  }
  else
  {
    bottomLeft_ = generateBasisHexagon(bottomLeft, sideForVerticalHexagon, false);
  }
}

double rychkov::Rectangle::getArea() const noexcept
{
  return bottomLeft_.getArea() * (localHeight_ * (localWidth_ / 2)
        - (localWidth_ % 2 == 0 ? localHeight_ / 2 : 0));
}
rychkov::rectangle_t rychkov::Rectangle::getFrameRect() const noexcept
{
  rectangle_t singleHexagonFrame = bottomLeft_.getFrameRect();
  rectangle_t result = singleHexagonFrame;
  if (singleHexagonFrame.height > singleHexagonFrame.width)
  {
    result.height *= (1.0 + 3.0 * localHeight_) / 4.0;
    result.width *= localWidth_ / 2.0;
  }
  else
  {
    result.height *= localWidth_ / 2.0;
    result.width *= (1.0 + 3.0 * localHeight_) / 4.0;
  }
  point_t center = singleHexagonFrame.pos;
  rychkov::move(center, -singleHexagonFrame.width / 2, -singleHexagonFrame.height / 2);
  rychkov::move(center, result.width / 2, result.height / 2);
  return {result.height, result.width, center};
}
void rychkov::Rectangle::move(point_t destination) noexcept
{
  point_t center = getFrameRect().pos;
  move(destination.x - center.x, destination.y - center.y);
}
void rychkov::Rectangle::move(double deltaX, double deltaY) noexcept
{
  bottomLeft_.move(deltaX, deltaY);
}
void rychkov::Rectangle::unsafeScale(double coef) noexcept
{
  point_t center = getFrameRect().pos;
  rychkov::unsafeScale(&bottomLeft_, coef, center);
}
rychkov::Shape* rychkov::Rectangle::clone() const
{
  Rectangle* result = static_cast< Rectangle* >(malloc(sizeof(Rectangle)));
  if (!result)
  {
    return nullptr;
  }
  return new (result) Rectangle(*this);
}

double rychkov::Rectangle::tryLocalRotation(double height, double width, double bestSideLength)
{
  constexpr long maxLoopDepth = 1e6;
  for (long localHeight = 1; localHeight < maxLoopDepth; localHeight++)
  {
    double localWidthMid = (1 + 3 * localHeight) * width / height / std::sqrt(3);
    double localWidthMin = localWidthMid * (1 - maxError);
    double localWidthMax = localWidthMid / (1 - maxError);
    long localWidth = std::ceil(localWidthMin);
    long localWidthEnd = std::floor(localWidthMax);

    for (; localWidth < localWidthEnd; localWidth++)
    {
      double sideLength = getSideLength(localHeight, localWidth, height, width);
      if (sideLength > 0)
      {
        if (sideLength > bestSideLength)
        {
          localHeight_ = localHeight;
          localWidth_ = localWidth;
        }
        return sideLength;
      }
    }
  }
  return 0;
}
double rychkov::Rectangle::getSideLength(long localHeight, long localWidth,
    double height, double width)
{
  double sideMaximum1 = 2 * height / (1 + 3 * localHeight);
  double sideMaximum2 = 2 * width / std::sqrt(3) / localWidth;
  double sideMaximum = std::min(sideMaximum1, sideMaximum2);
  double sideMinimum = std::max(sideMaximum1, sideMaximum2) * (1 - maxError);
  if (sideMaximum >= sideMinimum)
  {
    double square = sideMaximum * sideMaximum * std::sqrt(27) / 2 * (localHeight
            * (localWidth / 2) - (localWidth % 2 == 0 ? localHeight / 2 : 0));
    if (square >= height * width * (1 - maxError))
    {
      return sideMaximum;
    }
  }
  return 0;
}
rychkov::Regular rychkov::Rectangle::generateBasisHexagon(point_t bottomLeft,
    double sideLength, bool isHorizontal)
{
  double innerRadius = sideLength * std::cos(rychkov::PI / 6);
  if (isHorizontal)
  {
    point_t center = {bottomLeft.x + sideLength, bottomLeft.y + innerRadius};
    point_t p2 = {bottomLeft.x + sideLength / 2, bottomLeft.y};
    point_t p3 = {bottomLeft.x + sideLength, bottomLeft.y};
    return {center, p2, p3};
  }
  else
  {
    point_t center = {bottomLeft.x + innerRadius, bottomLeft.y + sideLength};
    point_t p2 = {bottomLeft.x, bottomLeft.y + sideLength / 2};
    point_t p3 = {bottomLeft.x, bottomLeft.y + sideLength};
    return {center, p2, p3};
  }
}
