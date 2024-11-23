#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments!" << '\n';
    return 1;
  }
  else if (argc < 4)
  {
    std::cerr << "Not enough arguments!" << '\n';
    return 1;
  }
  else if (!std::isdigit(argv[1][0]) || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not a number!" << '\n';
    return 1;
  }

  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is must be 1 or 2!" << '\n';
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!input)
  {
    std::cerr << "File is empty!" << "\n";
    return 2;
  }
  if (m * n == 0)
  {
    output << "0" << '\n';
    return 0;
  }

  int fixArr[10000] = {0};
  int * matrix = nullptr;
  int * dinamArr = nullptr;

  if (argv[1][0] == '1')
  {
    matrix = fixArr;
  }
  else if (argv[1][0] == '2')
  {
    try
    {
      dinamArr = new int[m * n];
      matrix = dinamArr;
    }
    catch(const std::bad_alloc & e)
    {
      delete[] dinamArr;
      std::cerr << "Out of memory!" << '\n';
      return 1;
    }
  }

  output << //funtions
  output << //funtions2
  delete[] dinamArr;
}
