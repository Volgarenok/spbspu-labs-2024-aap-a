#include <iostream>
#include <string>
#include "shape.hpp"
#include "base-types.hpp"
#include "fabric.hpp"
#include "additional-utilities.hpp"
using namespace nikonov;
int main()
{
  Shape *shapeCollection[10000] = {};
  size_t cnt = 0;
  size_t noncorrect = 0;
  try
  {
    fillShapeCollection(std::cin, shapeCollection, cnt, noncorrect);
    processCollection(std::cin, std::cout, shapeCollection, cnt);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    destoy(shapeCollection, cnt);
    return 1;
  }
  if (noncorrect)
  {
    std::cerr << "It was '" << noncorrect << "' noncorrect figures\n";
  }
  destoy(shapeCollection, cnt);
}
