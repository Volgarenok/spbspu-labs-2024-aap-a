#include "shape.hpp"
#include "inputShape.hpp"
#include <iostream>

int main()
{
  
  constexpr int maxShapes = 10000;
  maslov::Shape * shapes[maxShapes] = {};
  maslov::inputShape(std::cin, shapes);
}

