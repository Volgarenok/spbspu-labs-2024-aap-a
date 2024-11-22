#include <iostream>
#include <read_string.hpp>

const char* is_symbol(const char* str, char c)
{
  return ((str != nullptr) && (*str == c)) ? (str + 1) : nullptr;
}

const char* is_sign(const char* str)
{
  return ((str != nullptr) && ((*str == '+') || (*str == '-'))) ? (str + 1) : nullptr;
}

const char* is_digit(const char* str)
{
  return ((str != nullptr) && (*str >= '0') && (*str <= '9')) ? (str + 1) : nullptr;
}

const char* is_unsigned_integer(const char* str)
{
  if (str == nullptr) {
    return nullptr;
  }
  auto next = is_digit(str);
  if (next == nullptr) {
    return nullptr;
  }
  auto next2 = is_unsigned_integer(next);
  return (next2 == nullptr) ? next : next2;
}

const char* is_exponent(const char* str)
{
  if (str == nullptr) {
    return nullptr;
  }
  auto next = is_symbol(str, 'E');
  if (next == nullptr) {
    return nullptr;
  }
  auto next2 = is_sign(next);
  if (next2 != nullptr) {
    next = next2;
  }
  next = is_unsigned_integer(next);
  return next;
}

const char* is_mantissa(const char* str)
{
  if (str == nullptr) {
    return nullptr;
  }
  auto next = is_symbol(str, '.');
  if (next == nullptr) {
    next = is_unsigned_integer(str);
    next = is_symbol(next, '.');
  }
  return is_unsigned_integer(next);
}

const char* is_real(const char* str)
{
  if (str == nullptr) {
    return nullptr;
  }
  auto next = is_sign(str);
  if (next == nullptr) {
    next = str;
  }
  next = is_mantissa(next);
  return is_exponent(next);
}

bool is_match_pattern(const char* str)
{
  auto next = is_real(str);
  return ((next != nullptr) && (*next == '\0'));
}

int main()
{
  char* str = zholobov::read_string(std::cin);
  if (str == nullptr) {
    std::cerr << "Failed to read input string\n";
    return 1;
  }
  std::cout << std::boolalpha << is_match_pattern(str) << "\n";
  std::free(str);
}
