#include "table.hpp"

bool isNumbers(char* t)
{
  size_t i = 0;
  while (t[i] != '\0')
  {
    if (t[i] < '0' || t[i] > '9')
    {
      return false;
    }
    ++i;
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
