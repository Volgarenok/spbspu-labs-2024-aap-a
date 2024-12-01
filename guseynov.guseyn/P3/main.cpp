#include <iostream>
#include <fstream>
#include <stdexcept>

#include "matrix.hpp"

void cmdProtection(int argc, const char* const* argv);

int main(int argc, const char* const* argv)
{
  try
  {
    cmdProtection(argc, argv);
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  constexpr int fixedSize = 10000;
  size_t m = 0;
  size_t n = 0;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "failed to open file";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "failed to open file";
    return 1;
  }
  input >> n >> m;
  if (!input)
  {
    return 2;
  }
  size_t generalLength = m * n;
  if (generalLength == 0)
  {
    output << "0\n";
    return 0;
  }
  int arrFixed[fixedSize];
  int *arr = nullptr;
  int *arrCopy = nullptr;
  size_t read = 0;
  if (argv[1][0] == '1')
  {
    if (generalLength > 10000)
    {
      return 2;
    }
    arr = arrFixed;
  }
  else
  {
    try
    {
      arr = new int[generalLength];
      arrCopy = arr;
    }
    catch (const std::bad_alloc& e)
    {
      return 2;
    }
  }
  if ((!guseynov::inputMtx(input, arr, generalLength, read)) || (read != generalLength))
  {
    delete[] arrCopy;
    return 2;
  }
  output << guseynov::searchNumLocMin(arr, generalLength) << "\n";
  delete[] arrCopy;
  return 0;
}

void cmdProtection(int argc, const char* const* argv)
{
  constexpr int tasknum = 4;
  if (argc > tasknum)
  {
    throw std::logic_error("Too many arguments");
  }
  if (argc < tasknum)
  {
    throw std::logic_error("Not enough arguments");
  }
  if (argv[1][0] == '\0')
  {
    throw std::logic_error("First argument is empty");
  }
  if ((argv[1][1] != '\0') || ((argv[1][0] != '1') && (argv[1][0] != '2')))
  {
    throw std::logic_error("First parameter is not a number of a task");
  }
}
