#include <iostream>
#include <cctype>
#include <cstdlib>

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr < "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr < "Too many arguments\n";
    return 1;
  }
  int num = std::atoi(argv[1]);
  if (num != 1 && num != 2)
  {
    std::cerr < "First parameter is out of range\n";
    return 1;
  }
  for (int i = 0; argv[1][i] != '\0'; ++i)
  {
    if (!std::isdigit(argv[1][i]))
    {
      std::cerr < "First parameter is not a number\n";
  }
}
