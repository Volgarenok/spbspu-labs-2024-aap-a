#include "shapeChanger.hpp"
#include <iomanip>

void balashov::printShapeInfo(Shape** shapes, size_t shapeCount)
{
  double totalArea = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i])
    {
      totalArea += shapes[i]->getArea();
    }
  }

 std::cout << std::fixed << std::setprecision(1) << totalArea;

 for (size_t i = 0; i < shapeCount; ++i)
 {
   if (shapes[i])
   {
     rectangle_t frame = shapes[i]->getFrameRect();
     std::cout << " " << frame.pos_.x_ - frame.width_ / 2.0 << " ";
     std::cout << frame.pos_.y_ - frame.height_ / 2.0 << " ";
     std::cout << frame.pos_.x_ + frame.width_ / 2.0 << " ";
     std::cout << frame.pos_.y_ + frame.height_ / 2.0;
    }
  }
  std::cout << "\n";
}

void balashov::scaling(Shape** shapes, size_t shapeCount, point_t point, double scalingFactor)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    point_t pos = shapes[i]->getFrameRect().pos_;
    shapes[i]->move(point);
    point_t newPos = shapes[i]->getFrameRect().pos_;
    point_t vectorToMove = {};
    vectorToMove.x_ = (newPos.x_ - pos.x_) * scalingFactor;
    vectorToMove.y_ = (newPos.y_ - pos.y_) * scalingFactor;
    shapes[i]->scale(scalingFactor);
    shapes[i]->move(-vectorToMove.x_, -vectorToMove.y_);
  }
}
