#include <iostream>
#include <fstream>
#include <cstdlib>
#include "mtx_transform.hpp"
int main(int argc, char ** argv)
{
  if (!nikonov::inputCheck(argc, argv)){
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t m = 0;
  size_t n = 0;
  input >> m;
  input >> n;
  size_t read = 0;
  if (atoi(argv[1]) == 1)
  {
    int arr[10000] = { 0 };
    if (!nikonov::readMatrix(input, arr, m, n, read))
    {
      std::cerr << "ERROR: incorrect input\n";
      return 2;
    }
    nikonov::transformMatrix(arr, m, n);
    nikonov::printMatrix(output, arr, m, n);
  }
  else
  {
    int* arr = nullptr;
    try
    {
      arr = new int[m * n];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "ERROR: " << e.what() << "\n";
      return 1;
    }
    if (!nikonov::readMatrix(input, arr, m, n, read))
    {
      std::cerr << "ERROR: incorrect input\n";
      delete[] arr;
      return 2;
    }
    nikonov::transformMatrix(arr, m, n);
    nikonov::printMatrix(output, arr, m, n);
    delete[] arr;
  }
}
