#include <iostream>
bool isSign(char c)
{
  return (c == '+') || (c == '-');
}
int main()
{
  auto a = "-1.23456789E9234";
  std::cout << "Test" << "\n";
  std::cout << std::boolalpha << isDouble(a) << "\n";
}



