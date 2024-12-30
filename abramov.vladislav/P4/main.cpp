#include <cstring>
#include <getString.hpp>
#include "unionStrs.hpp"
int main()
{
  constexpr const char *str2 = "def ";
  size_t size_of_str1 = 0;
  char *str1 = abramov::getStr(std::cin, size_of_str1);
  if (str1 == nullptr)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  if (str1[0] == '\0')
  {
    std::cerr << "Incorrect input\n";
    delete[] str1;
    return 1;
  }
  char *destination = nullptr;
  constexpr size_t size_of_str2 = 4;
  try
  {
    destination = new char[size_of_str1 + size_of_str2 + 1];
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory fail\n";
    delete[] str1;
    return 2;
  }
  destination = abramov::unionStrs(destination, str1, str2);
  std::cout << destination << "\n";
  delete[] str1;
  delete[] destination;
}
