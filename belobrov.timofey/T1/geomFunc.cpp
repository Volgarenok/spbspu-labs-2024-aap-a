#include "geomFunc.hpp"
#include <iostream>

namespace belobrov
{
  void deleteShapes(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i) {
      delete shapes[i];
    }
  }
  void outputFrameCoordinates(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i) {
      rectangle_t frame = shapes[i]->getFrameRect();
      if (i > 0) {
        std::cout << " ";
      }
      std::cout << frame.pos.x - frame.width / 2 << " " << frame.pos.y - frame.height / 2;
      std::cout << " " << frame.pos.x + frame.width / 2 << " " << frame.pos.y + frame.height / 2;
    }
  }
}
