#include <iostream>
#include <string>
#include "shape.hpp"
#include "fabric.hpp"
int main()
{
  std::string name = "";
  std::cin >> name;
  float nums[4] = { 0 };
  for (size_t i = 0; i < 4; ++i)
  {
    std::cin >> nums[i];
  }
  if (!std::cin)
  {
    std::cerr << "ERROR: not a value\n";
  }
  nikonov::Shape* testRec = nikonov::make_shape(name, nums);
  std::cout << testRec->getArea();
  delete testRec;
}
