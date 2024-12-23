#include <iostream>
#include <ios>
#include <cstddef>
int main()
{
  size_t max = 10;
  char str[max + 1] = {};
  size_t size = 0;
  char c = '\0';
  std::noskipws(std::cin);
  
  while ((std::cin >> c) && (c != '\n') && (size < max))
  {
    str[size++] = c;
  }
  std::skipws(std::cin);
  
  std::cout << size << "\n";
  std::cout << str << "\n";
}
