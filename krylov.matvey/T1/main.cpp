#include <iostream>
#include <stdexcept>
#include "processShapes.hpp"

int main()
{
  try
  {
    krylov::processShapes();
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
}

