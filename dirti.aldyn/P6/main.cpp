#include <iostream>
#include <ios>
#include <str_input.hpp>
#include "is_expression.hpp"

int main()
{
  size_t capacity = 2;
  const char * str = dirti::str_input(std::cin, capacity);
  std::cout << std::boolalpha << dirti::is_expression(str);
}
