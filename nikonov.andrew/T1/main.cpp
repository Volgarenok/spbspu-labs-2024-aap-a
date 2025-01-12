#include <iostream>
#include <string>
#include "shape.hpp"
#include "fabric.hpp"
#include "additional-utilities.hpp"
#include "composite-shape.hpp"
int main()
{
  using namespace nikonov;
  CompositeShape shapeCollection;
  try
  {
    fillShapeCollection(std::cin, std::cerr, shapeCollection);
    processCollection(std::cin, std::cout, shapeCollection);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    destoy(shapeCollection);
    return 1;
  }
}
