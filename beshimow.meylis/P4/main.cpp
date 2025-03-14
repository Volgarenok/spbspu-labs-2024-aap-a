#include <iostream>
#include "stringProcessor.hpp"

int main()
{
  const size_t MAX_SIZE = 1024;
  char input[MAX_SIZE];

  std::cout << "Введите строку: ";
  if (!std::cin.getline(input, MAX_SIZE))
  {
    std::cerr << "Ошибка: не удалось считать строку." << std::endl;
    return 1;
  }

  const char* excludeStr = "aeiou";

  char* result = excludeCharacters(input, excludeStr);
  if (result == nullptr)
  {
    std::cerr << "Ошибка: не удалось выделить память." << std::endl;
    return 1;
  }

  std::cout << "Результат: " << result << std::endl;

  delete[] result;

  return 0;
}
