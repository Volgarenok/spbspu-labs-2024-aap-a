#include <iostream>
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
    return 1;
  }
}
