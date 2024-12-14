#include <iostream>
#include <string>
#include "shape.hpp"
#include "fabric.hpp"
#include "scale.hpp"
#include "fillShapeCollection.hpp"
int main()
{
  nikonov::Shape* shapeCollection[10000] = { nullptr };
  std::string name = "";
  size_t cnt = 0, noncorrect = 0;
  nikonov::fillShapeCollection(shapeCollection, cnt, noncorrect);
  float x = 0, y = 0;
  float k = 0;
  std::cin >> x >> y >> k;
  if (std::cin)
  {
    nikonov::Shape* next = shapeCollection[0];
    while (next)
    {
      nikonov::ispScale(next, x, y, k);
    }
  }
  for (size_t i = 0; i < cnt; ++i)
  {
    delete shapeCollection[i];
  }
}
