#include <stdexcept>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
  int num = 0;
  try
  {
    if (argc != 4)
    {
      throw std::logic_error("Wrong number of parametres");
    }
    const char *str = argv[1];
    char *str_end = nullptr;
    long long num = 0;
    num = std::strtoll(str, &str_end, 10);
    if (*str_end != '\0' || num == 0)
    {
      throw std::logic_error("Can not parse value");
    }
    if (num != 1 && num != 2)
    {
      throw std::logic_error("Incorrect parametr");
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
}
