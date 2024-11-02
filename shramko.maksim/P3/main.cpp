#include <iostream>
#include <cdtring>

int main(int argc, char** argv)
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

  const char* str = argv[1];
  char* pEnd;
  long int number = 0;
  number = str::strtol(str, &pEnd, 10)

  if (number != 1 && number != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  for (size_t i = 0; i < strlen(str); ++i)
  {
    if (str[i] < "0" || str[i] > "9")
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }
}
