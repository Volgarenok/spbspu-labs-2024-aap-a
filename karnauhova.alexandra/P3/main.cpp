#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char ** argv)
{
  int fix_matrix[10000] = {};
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
  if (!isdigit(argv[1]))
  }
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  const int way = std::atoi(argv[1]);
  if (way > 2 | way < 1)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  input >> m;
  std::cout << m << "\n";
  if (way == 2)
  {
    //alloc(m, n);
  }


  std::cout<<way<<"\n";
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i]<<"\n";
  }
  std::cout << argc;
}
