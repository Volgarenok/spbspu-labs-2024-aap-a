#include <iostream>
#include <fstream>
#include <cstdlib>
#include "mtx_transform.hpp"

int main(int argc, char ** argv)
{
  if (!inputCheck(argc, argv)){
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
    if (!readMatrix(input, arr, m, n, read))
    {
      std::cerr << "ERROR: incorrect input\n";
      return 2;
    }
    printMatrix(output, arr, m, n);
  }
  else 
  {
    int* arr = new int[m * n];
    readMatrix(input, arr, m, n, read);
    if (!readMatrix(input, arr, m, n, read))
    {
      std::cerr << "ERROR: incorrect input\n";
      delete[] arr;
      return 2;
    }
    printMatrix(output, arr, m, n);
    delete[] arr;
  }
}
