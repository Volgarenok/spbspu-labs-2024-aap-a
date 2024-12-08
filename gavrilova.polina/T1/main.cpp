#include <iostream>
#include <string>
#include <inputStr.hpp>
#include "fabric_shape.hpp"
int main()
{
  gavrilova::Shape * Rect = nullptr;
  Rect = gavrilova::fabric_shape(std::cin);
  gavrilova::rectangle_t square = Rect->getFrameRect();
  std::cout << square.height;
}
