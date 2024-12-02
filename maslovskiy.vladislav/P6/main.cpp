#include <iostream>
#include <cctype>

bool isSign(char c)
{
  return (c == '+') || (c == '-');
}
const char *hasDigit(const char *str)
{
  if (!str)
  {
    return str;
  }
  return isdigit(*str) ? (str + 1) : nullptr;
}
int main()
{
  auto a = "-1.23456789E9234";
  std::cout << "Test" << "\n";
  std::cout << std::boolalpha << isDouble(a) << "\n";
}



