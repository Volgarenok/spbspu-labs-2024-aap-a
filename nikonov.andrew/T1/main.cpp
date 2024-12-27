#include <iostream>
#include <string>
#include "shape.hpp"
#include "base-types.hpp"
#include "fabric.hpp"
#include "additional-utilities.hpp"
int main()
{
  nikonov::Shape *shapeCollection[10000] = {nullptr};
  std::string name = "";
  size_t cnt = 0;
  size_t noncorrect = 0;
  nikonov::fillShapeCollection(std::cin, shapeCollection, cnt, noncorrect);
  if (nikonov::processCollection(std::cin, shapeCollection, cnt))
  {
    return 1;
  }
  if (noncorrect)
  {
    std::cerr << "It was '" << noncorrect << "' noncorrect figures\n";
  }
  nikonov::destoy(shapeCollection, cnt);
}
