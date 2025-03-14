#include <iostream>
#include <inputStr.hpp>
#include "findMin.hpp"
#include "findTwoMin.hpp"
#include "findMinRecursed.hpp"

int main()
{
  size_t capacity = 1;
  char * str = dirti::inputStr(std::cin, capacity);
  if (str == nullptr)
  {
    std::cerr << "Error" << "\n";
    return 1;
  }
  char str_min = dirti::findMin(str);
  std::cout << str_min << "\n";
  char str_min2[2] = {'0', '0'};
  dirti::findTwoMin(str, str_min2);
  if (str_min2[1] == str_min2[0])
  {
    std::cout << "There is only one symbol" << "\n";
  }
  else
  {
    std::cout << str_min2[0] << " " << str_min2[1] << "\n";
  }
  char str_min_recursed = dirti::findMinRecursed(str);
  std::cout << str_min_recursed << "\n";
  free(str);
}
