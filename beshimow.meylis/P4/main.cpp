#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

constexpr size_t BUFFER_INCREMENT = 16;

void excludeCharacters(char* str1, const char* str2);

int main()
{
  size_t capacity = BUFFER_INCREMENT;
  size_t size = 0;
  char* input = static_cast<char*>(std::malloc(capacity));

  if (!input)
  {
    std::cerr << "Ошибка: не удалось выделить память." << std::endl;
    return 1;
  }

  char ch;
  while (std::cin.get(ch) && ch != '\n')
  {
    if (size + 1 >= capacity)
    {
      capacity += BUFFER_INCREMENT;
      char* newBuffer = static_cast<char*>(std::realloc(input, capacity));
      if (!newBuffer)
      {
        std::cerr << "Ошибка: не удалось выделить память." << std::endl;
        std::free(input);
        return 1;
      }
      input = newBuffer;
    }
    input[size++] = ch;
  }
  input[size] = '\0';

  if (size == 0)
  {
    std::cerr << "Ошибка: пустая строка" << std::endl;
    std::free(input);
    return 1;
  }

  const char* excludeStr = "abc";
  excludeCharacters(input, excludeStr);

  std::cout << input << std::endl;

  std::free(input);
  return 0;
}
