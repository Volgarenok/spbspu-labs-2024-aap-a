#include "string.hpp"

int main()
{
  char * str = mozhegova::inputString(std::cin, '\n');
  if (str == nullptr)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  for (size_t i = 0; i != '\n'; i++)
  {
    std::cout << str[i];
  }
  std::cout << '\n';
  char * result = mozhegova::spcRmv(str);
  for (size_t i = 0; i != '\n'; i++)
  {
    std::cout << result[i];
  }
  std::cout << '\n';
  delete[] str;
}
