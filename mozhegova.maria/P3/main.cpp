#include <iostream>
#include <cctype>

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (mozhegova::isNumber(argv[1]) && argv[1] != "1" && argv[1] != "2")
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  if (!mozhegova::isNumber(argv[1]))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
}
