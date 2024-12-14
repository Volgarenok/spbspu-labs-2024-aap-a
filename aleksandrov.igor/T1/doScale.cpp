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

  double scaleX = std::stod(getWord(scaleParams, 1));
  double scaleY = std::stod(getWord(scaleParams, 2));
  double k = std::stod(getWord(scaleParams, 3));
  if (paramsCount != 3)
  {
    return nullptr;
  }
  rectangle_t frameRect = shape->getFrameRect();
  double centerX = frameRect.pos_.x_;
  double centerY = frameRect.pos_.y_;
  double dx = scaleX - centerX;
  double dy = scaleY - centerY;
  shape->move({scaleX, scaleY});
  shape->scale(k);
  shape->move(-dx * k, -dy * k);
  return shape;
}
