#include "unionString.hpp"

int main()
{
  const char * str2 = "def ";
  char * str1 = nullptr;
  try
  {
    str1 = smirnov::getLine(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (str1[0] == '\0')
  {
    delete[] str1;
    std::cerr << "Error: empty string\n";
    return 1;
  }
  char * result_str = nullptr;
  constexpr size_t new_size = 255;
  try
  {
    result_str = new char[new_size];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] str1;
    std::cerr << "Out of memory\n";
    return 1;
  }
  smirnov::uniString(result_str, str1, str2);
  std::cout << result_str << "\n";
  delete[] result_str;
  delete[] str1;
}
