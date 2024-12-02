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
const char *hasChar(const char *str, char c)
{
  if (!str)
  {
    return str;
  }
  return *str == c ? (str + 1) : nullptr;
}
const char *hasSign (const char *str)
{
  if (!str)
  {
    return str;
  }
  return isSign(*str) ? (str + 1) : nullptr;
}
const char *hasNumbers(const char *str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasDigit(str);
  if (auto continues = hasNumbers(next))
  {
    return continues;
  }
  return next;
}
const char *hasMantissa(const char *str)
{
  auto next = hasDigit(str);
  next = hasChar(next, '.');
  next = hasNumbers(next);
  return next;
}
const char *hasExponent(const char *str)
{
  auto next = hasChar(str, 'E');
  if (auto continues = hasSign(next))
  {
    next = continues;
  }
  next = hasNumbers(next);
  return next;
}
bool isDouble(const char *str)
{
  auto next = str;
  if (auto continues = hasSign(next))
  {
    next = continues;
  }
  next = hasMantissa(next);
  next = hasExponent(next);
  return *next == '\0' && next;
}
int main()
{
  auto a = "-1.23456789E9234";
  std::cout << "Test" << "\n";
  std::cout << std::boolalpha << isDouble(a) << "\n";
}
