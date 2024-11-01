#include "table.hpp"
#include <cstring>


bool isNumbers(char* t)
{
  for (size_t i = 0; i < strlen(t); ++i)
  {
    if (t[i] > '9' || t[i] < '0')
    {
      return false;
    }
  }
  return true;
}

std::istream& inputTable(std::istream& inputFile, int* arr, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    inputFile >> arr[i];
  }
  return inputFile;
}

void outputTable(std::ostream& outputFile, int* arr, size_t m)
{
  size_t size = m * m;
  bool flag = true;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = i + 1; j < m; ++j)
    {
      if (arr[i * m + j] != 0)
      {
        flag = false;
        break;
      }
    }
  }
  if (flag && m > 1)
  {
    outputFile << "true";
  }
  else
  {
    outputFile << "false";
  }
}
