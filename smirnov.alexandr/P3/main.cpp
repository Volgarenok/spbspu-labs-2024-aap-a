#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>

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
  int num = std::atoi(argv[1]);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  for (int i = 0; argv[1][i] != '\0'; ++i)
  {
    if (!std::isdigit(argv[1][i]))
    {
      std::cerr << "First parameter is not a number\n";
    }
  }
  std::ifstream input();
  size_t rows = 0;
  size_t cols = 0;
  input >> rows >> cols;
  if (!input || rows <= 0 || cols <= 0)
  {
    std::cerr << "Invalid matrix dimensions\n";
  }
  if (rows * cols > 10000)
  {
    std::cerr << "The size of the matrix is exceeded\n";
  }
  if (num == 1)
  {
    constexpr size_t size = 10000;
    int matrix[size] = {0};
  }
}

