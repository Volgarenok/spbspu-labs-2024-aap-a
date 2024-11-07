#include <iostream>

std::size_t isSameSymbols(const char* const str1, const char* const str2)
{
  size_t counterArray[256] = {0};

  for (size_t i = 0; str1[i] != '\0'; ++i)
  {
    ++counterArray[str1[i]];
  }
  for (size_t i = 0; str2[i] != '\0'; ++i)
  {
    if (counterArray[str2[i]])
    {
      return 1;
      break;
    }
  }

  return 0;
}

int main()
{
  constexpr char constString[25] = "~9R hg,3hX i%htQ/K*Y.35T";
  char symbol = '\0';
  constexpr std::size_t stringCapacity = 10;
  std::size_t stringIndex = 0;
  char* dynamicString = nullptr;

  try
  {
    dynamicString = new char[stringCapacity + 1];
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  std::noskipws(std::cin);
  while ((std::cin >> symbol) && (symbol != '\n'))
  {
    if (stringIndex == stringCapacity)
    {}
     dynamicString[stringIndex] = symbol;
  }
  std::skipws(std::cin);

  std::cout << isSameSymbols(constString, dynamicString);
  std::cout << '\n';
}
