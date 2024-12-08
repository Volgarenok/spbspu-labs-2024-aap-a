#include "fabric.hpp"
#include <iostream>
#include <string>
#include "shape.hpp"
nikonov::Shape* nikonov::make_rectangle(std::istream& input)
{
  std::string name;
  input >> name;
  std::cout << name << '\n';
  return nullptr;
}