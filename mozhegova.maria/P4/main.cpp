#include "string.hpp"

int main()
{
  char * str = nullptr;
  try
  {
    char * str = mozhegova::inputString(std::cin, '\n');
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  char * result = mozhegova::spcRmv(str);
  for (size_t i = 0; i != '\n'; i++)
  {
    std::cout << result[i];
  }
  std::cout << '\n';
}
