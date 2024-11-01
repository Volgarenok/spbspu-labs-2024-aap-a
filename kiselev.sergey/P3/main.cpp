#include <cstddef>
#include <iostream>
int main(int argc, char** argv)
{
  if (argv[1][0] == 1)
  {

    size_t k = 1000;
    int* odnom_array = nullptr;
    try
    {
      odnom_array = new int[k];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Memory was not allocated\n";
    }
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "To many arguments\n";
  }
}

