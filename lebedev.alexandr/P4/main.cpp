#include <iostream>
#include "rmv_vow.hpp"

int main()
{
  char* str = nullptr;
  size_t capacity = 10;
  try
  {
    str = lebedev::getLine(std::cin, capacity, '\n');
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation error!\n";
    return 2;
  }
  if (!std::cin)
  {
    std::cerr << "Incorrect input!\n";
    delete[] str;
    return 1;
  }

  char* str_without_vowels = nullptr;
  try
  {
    str_without_vowels = new char[capacity];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation error!\n";
    delete[] str;
    return 2;
  }

  lebedev::removeVowels(str, str_without_vowels);
  std::cout << str_without_vowels << '\n';
  delete[] str;
  delete[] str_without_vowels;
  return 0;
}
