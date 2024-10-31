#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <cstddef>
int* ct_table(size_t m,size_t n);
std::istream & input_matrix(std::istream & in, int * t, size_t m, size_t n)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    in >> t[i];
  }
}
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
  char * number = argv[1];
  if (!isdigit(number[0]))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  size_t x = 1;
  while (number[x]!='\0')
  {
    if (!isdigit(number[x]))
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
    x++;
  }
  const int way = std::atoi(argv[1]);
  if (way > 2 | way < 1)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  int m = 0,n = 0;
  input >> m >> n;
  std::cout << m << n << "\n";
  if (way == 2)
  {
    int* t = ct_table(m,n);
  }
  else
  {
    int* t = fix_matrix;
  }
}
int* ct_table(size_t m,size_t n){
  int* matrix = nullptr;
  try
  {
    matrix = new int[m*n];
  }
  catch(const std::bad_alloc &e)
  {
    delete[] matrix;
    throw;
  }
  return matrix;
}
