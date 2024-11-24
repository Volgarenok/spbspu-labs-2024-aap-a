#include <iostream>
#include <ios>
#include <getline.hpp>

bool isRealNumber(const char *str)
{
  
}

int main()
{
  char *str = nullptr;
  try
  {
    str = sveshnikov::read_str(std::cin);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "ERROR: BAD_ALLOC! " << e.what() << '\n';
    return 1;
  }
  if (str[0] == '\0')
  {
    std::cerr << "ERROR: EMPTY INPUT\n";
    delete[] str;
    return 1;
  }
  std::cout << std::boolalpha << isRealNumber(str) << "\n";
}
