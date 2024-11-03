#include <iostream>
#include <fstream>

size_t cstring_len(char* s)
{
  size_t len = 0;
  for (; s[len] != 0; len++);
  return len;
}

std::istream & input(std::istream & in, int* arr, size_t m, size_t n, size_t &read)
{
  int num = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      in >> num;
      if (in.good())
      {
        read++;
      }
      arr[i * n + j] = n;
    }
  }
  return in;
}

bool isRowNsm(int* arr, size_t i, size_t n)
{
  bool isNsm = true;
  for(size_t j = 1; j < n; j++)
  {
    if (arr[i * n + j] == arr[i * n + j - 1])
    {
      isNsm = 0;
    }
  }
  return isNsm;
}

size_t CntRowsNsm(int* arr, size_t m, size_t n)
{
  size_t ans = 0;
  for (size_t i = 0; i < m; i++)
  {
    ans += isRowNsm(arr, i, n);
  }
  return ans;
}

int main(int argc, char** argv)
{
  constexpr size_t StaticArrSize = 1e4;
  if(argc != 4)
  {
    std::cerr << "bad\n";
    return 1;
  }
  std::ifstream fin(argv[2]);
  std::ofstream fout(argv[3]);
  size_t m = 0, n = 0;
  fin >> m >> n;
  if ((cstring_len(argv[1]) == 1))
  {
    int num = 0;
    num = atoi(argv[1]);
    int* arr = nullptr;
    if (num == 1)
    {
      int arr[StaticArrSize];
    }
    else if(num == 2)
    {
      try
      {
        int* arr = new int[m * n];
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
        delete[] arr;
        return 1;
      }
    }
    else
    {
      return 1;
    }
    size_t read = 0;
    if ((input(fin, arr, m, n, read).good()))
    {
      std::cout << CntRowsNsm(arr, m, n) << "\n";
    }
    if(num == 2)
    {
      delete[] arr;
    }
  }
  return 0;
}