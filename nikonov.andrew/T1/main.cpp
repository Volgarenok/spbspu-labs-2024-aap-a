#include <iostream>
#include <string>
#include "shape.hpp"
#include "base-types.hpp"
#include "fabric.hpp"
#include "additional-utilities.hpp"
int main()
{
  nikonov::Shape *shapeCollection[10000] = {nullptr};
  size_t cnt = 0;
  size_t noncorrect = 0;
  try
  {
    nikonov::fillShapeCollection(std::cin, shapeCollection, cnt, noncorrect);
    nikonov::processCollection(std::cin, shapeCollection, cnt);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    nikonov::destoy(shapeCollection, cnt);
    return 1;
  }
  if (noncorrect)
  {
    std::cerr << "It was '" << noncorrect << "' noncorrect figures\n";
  }
  nikonov::destoy(shapeCollection, cnt);
}
