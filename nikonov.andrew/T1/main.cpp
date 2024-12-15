#include <iostream>
#include <string>
#include "shape.hpp"
#include "base-types.hpp"
#include "fabric.hpp"
#include "scale.hpp"
#include "additional-utilities.hpp"
int main()
{
  nikonov::Shape* shapeCollection[10000] = { nullptr };
  std::string name = "";
  size_t cnt = 0, noncorrect = 0;
  nikonov::fillShapeCollection(shapeCollection, cnt, noncorrect);
  float x = 0, y = 0;
  float k = 0;
  std::cin >> x >> y >> k;
  float s1 = 0, s2 = 0;
  if (std::cin)
  {
    nikonov::Shape* current = shapeCollection[0];
    while (current)
    {
      nikonov::rectangle_t tempRect = current->getFrameRect();
      s1 += tempRect.height_ * tempRect.width_;
      nikonov::ispScale(current, x, y, k);
      ++current;
    }
  }
  nikonov::destoy(shapeCollection, cnt);
}
