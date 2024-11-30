#include <iostream>
#include <inputString.hpp>

int main()
{
  char* str = shramko::inputString(std::cin);
  if (str == nullptr)
  {
    std::cerr << "String error!\n";
    return 1;
  }

  if (str[0] == '\0')
  {
    free(str);
    std::cerr << "String is empty!\n";
    return 1;
  }

  std::cout << std::boolalpha << shramko::isExpression(str) << '\n';
  free(str);
}
