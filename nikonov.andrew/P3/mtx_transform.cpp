#include "mtx_transform.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
bool inputCheck(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 0;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 0;
  }
  if (strlen(argv[1]) != 1)
  {
    std::cerr << "First parameter is not a number\n";
    return 0;
  }
  else if (!atoi(argv[1]))
  {
    std::cerr << "First pararmetr is not a number\n";
  }
  return 1;
}
std::istream& readMatrix(std::istream& input, int* mtx, size_t m, size_t n, size_t& read)
{
  for (size_t i = 0; i < m * n; ++i)
  {
    if (!(input >> mtx[i]))
    {
      return input;
    }
    else 
    {
      ++read;
    }
  }
  return input;
}
void printMatrix(std::ostream& output, int* mtx, size_t m, size_t n)
{
  if (m > 0){
    output << mtx[0];
  }
  for (size_t i = 1; i < m * n; ++i)
  {
    if (i % n == 0)
    {
      output << "\n";
    }
    else 
    {
      output << " ";
    }
    output << mtx[i];
  }
}
