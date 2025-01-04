#include <iostream>
#include <string>
#include "shape.hpp"
#include "base-types.hpp"
#include "fabric.hpp"
#include "additional-utilities.hpp"
int main()
{
  using namespace nikonov;
  Shape *shapeCollection[10000] = {};
  size_t cnt = 0;
  try
  {
    fillShapeCollection(std::cin, shapeCollection, cnt);
    processCollection(std::cin, std::cout, shapeCollection, cnt);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    destoy(shapeCollection, cnt);
    return 1;
  }
  destoy(shapeCollection, cnt);
}
