#include <iostream>
#include <cstddef>
#include <ios>
#include "string.h"

int main()
{
  try
  {
    constexpr std::size_t max = 25;
    char str[max + 1] = {};
    std::size_t size = 0;
    char c = '\0';
    std::noskipws(std::cin);
    while ((std::cin >> c) && (c != '\n') && (size < max))
    {
      str[size++] = c;
    }
      std::skipws(std::cin);

  if (std::cin.bad())
  {
    std::cerr << "ERROR: entry data\n";
    return 1;
  }

  if (size == 0)
  {
  std::cerr << "ERROR: empty string\n";
  return 1;
  }

  if (size > max)
  {
    std::cerr << "ERROR: the string exceeds the maximum size\n";
    return 1;
  }

  char * result = cherkasov::getString(str, size);
  if (result)
  {
    std::cout << result << "\n";
    delete[] result;
  }

 }
   catch (const std::exception & e)
   {
     std::cerr << "An exception has occurred: " << e.what() << "\n";
     return 1;
   }

    return 0;
}
