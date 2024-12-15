#include <iostream>
#include <string>
#include "shape.hpp"
#include "base-types.hpp"
#include "fabric.hpp"
#include "additional-utilities.hpp"
int main()
{
  nikonov::Shape* shapeCollection[10000] = { nullptr };
  std::string name = "";
  size_t cnt = 0, noncorrect = 0;
  nikonov::fillShapeCollection(shapeCollection, cnt, noncorrect);
  if (nikonov::processCollection(shapeCollection, cnt))
  {
    return 1;
  }
  nikonov::destoy(shapeCollection, cnt);
}
