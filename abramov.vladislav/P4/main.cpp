#include <cstring>
#include "unionStrs.hpp"
#include <getString.hpp>
int main()
{
  constexpr const char *str2 = "def ";
  char *str1 = nullptr;
  char *destination = nullptr;
  try
  {
    str1 = abramov::getStr(std::cin);
    if (str1 != nullptr)
    {
      destination = new char [std::strlen(str1) + std::strlen(str2) + 1];
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory fail\n";
    delete[] str1;
    delete[] destination;
    return 2;
  }
  if (str1 == nullptr)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  if (str1[0] == '\0')
  {
    std::cerr << "Incorrect input\n";
    delete[] str1;
    delete[] destination;
    return 1;
  }
  destination = abramov::unionStrs(destination, str1, str2);
  std::cout << destination << "\n";
  delete[] str1;
  delete[] destination;
}
