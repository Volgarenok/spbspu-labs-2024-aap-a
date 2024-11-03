#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include "create_matrix.hpp"
#include "incomplete_matrix.hpp"
#include "input_output.hpp"

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
  char* str = argv[1];
  if (!std::isdigit(str[0]))
  {
    std::cerr << "First parameter is not suitable\n";
    return 1;
  }
  const int way = std::atoi(argv[1]);
  if ((way > 2) | (way < 1))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t read = 0;
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!input)
  {
    std::cerr << "File text is invalid\n";
    return 1;
  }
  if (m != n)
  {
    std::cerr << "Non-square matrix\n";
    return 1;
  }
  if (m == 0 && n == 0)
  {
    output << m << " " << n << " ";
    return 0;
  }
  int * t = nullptr;
  if (way == 2)
  {
    try
    {
      t = karnauhova::ct_matrix(m, n);;
    }
    catch(const std::bad_alloc & e)
    {
      std::cerr<<"Out of memory\n";
      return 1;
    };
  }
  int t1[10000] = {0};
  if (way == 2)
  {
    if (!karnauhova::input_matrix(input, t, m, n, read))
    {
        std::cerr << "File text is invalid\n";
        delete[] t;
        return 2;
    }
  }
  else
  {
    if (!karnauhova::input_matrix(input, t1, m, n, read))
    {
      std::cerr << "File text is invalid\n";
      return 2;
    }
  }
  if ((read / m) < n)
  {
    std::cerr << "Incorrect matrix\n";
    if (way == 2)
    {
      delete[] t;
    }
    return 1;
  }
  float* t2 = nullptr;
  try
  {
    if (way == 2)
    {
      t2 =  karnauhova::smooth_matrix(t, m, n);
    }
    else
    {
      t2 =  karnauhova::smooth_matrix(t1, m, n);
    }
   }
   catch(const std::bad_alloc & e)
   {
     std::cerr<<"Out of memory\n";
     return 1;
   }
  output << m << " " << n << " ";
  karnauhova::output_matrix(output, t2, m, n);
  output << "\n";
  delete[] t;
  delete[] t2;
  return 0;
}
