#include "doScale.h"
#include "getWord.h"

Shape* aleksandrov::doScale(const std::string scaleDescription, Shape* shape)
{
  std::string scaleParams, param;
  size_t paramsCount = 0;
  param = getWord(scaleDescription, paramsCount + 2);
  while (param != "")
  {
    if (paramsCount == 0)
    {
      scaleParams += param;
    }
    else
    {
      scaleParams += " " + param;
    }
    ++paramsCount;
    param = getWord(scaleDescription, paramsCount + 2);
  }

  point_t scalePoint;
  scalePoint.x_ = std::stod(getWord(scaleParams, 1));
  scalePoint.y_ = std::stod(getWord(scaleParams, 2));
  size_t k = std::stod(getWord(scaleParams, 3));
  if (paramsCount != 3 || k <= 0.0)
  {
    return nullptr;
  }

  point_t tempPoint = (shape->getFrameRect()).pos_;
  double dx = scalePoint.x_ - tempPoint.x_;
  double dy = scalePoint.y_ - tempPoint.y_;
  shape->move(scalePoint);
  shape->scale(k);
  dx /= k;
  dy /= k;
  shape->move(dx, dy);
  return shape;
}
