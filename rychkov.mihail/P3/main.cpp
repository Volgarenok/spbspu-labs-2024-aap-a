#include <iostream>
#include <fstream>

#include "get_max_sum_sdg.hpp"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "too many arguments\n";
    return 1;
  }
  if (*argv[1] == '\0')
  {
    std::cerr << "first argument is empty\n";
    return 1;
  }
  if ((argv[1][1] != '\0') || ((argv[1][0] != '1') && (argv[1][0] != '2')))
  {
    std::cerr << "first argument is not a number of a task\n";
    return 1;
  }

  std::ifstream in(argv[2]);
  if (!in.is_open())
  {
    std::cerr << "failed to open input file\n";
    return 1;
  }
  std::ofstream out(argv[3]);
  if (!out.is_open())
  {
    std::cerr << "failed to open output file\n";
    in.close();
    return 1;
  }

  int staticMatrix[10'000];

  in.close();
  out.close();
}
