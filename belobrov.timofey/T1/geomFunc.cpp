#include "geomFunc.hpp"
#include <iostream>

namespace belobrov
{
  void deleteShapes(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i) {
      if (shapes[i] != nullptr) {
        delete shapes[i];
      }
    }
  }

  void outputFrameCoordinates(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i) {
      if (shapes[i] != nullptr) {
        rectangle_t frame = shapes[i]->getFrameRect();
        if (i > 0) {
          std::cout << " ";
        }
        std::cout << frame.pos.x - frame.width / 2 << " " << frame.pos.y - frame.height / 2;
        std::cout << " " << frame.pos.x + frame.width / 2 << " " << frame.pos.y + frame.height / 2;
      }
    }
  }

  double calculateTotalArea(Shape** shapes, size_t count) {
    double totalArea = 0.0;
    for (size_t i = 0; i < count; ++i) {
      if (shapes[i] != nullptr) {
        totalArea += shapes[i]->getArea();
      }
    }
    return totalArea;
  }

  void applyIsoScaling(Shape** shapes, size_t count, const point_t& center, double factor) {
    for (size_t i = 0; i < count; ++i) {
      if (shapes[i] != nullptr) {
        point_t isCenter = shapes[i]->getFrameRect().pos;
        shapes[i]->scale(factor);
        shapes[i]->move(center.x - isCenter.x, center.y - isCenter.y);
      }
    }
  }
}
