#include "string.hpp"

int main()
{
  char * str = mozhegova::inputString(std::cin, '\n');
  if (str == nullptr)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  char * result = mozhegova::spcRmv(str);
  for (size_t i = 0; result[i] != '\0'; i++)
  {
    std::cout << result[i];
  }
  std::cout << '\n';
  delete[] str;
}
