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

void inputTable(std::istream& inputFile, int* arr, size_t size)
{

}

void outputTable(std::ostream& outputFile, int* arr, size_t size)
{
  outputFile << arr[0];
  for (size_t i = 1; i < size; ++i)
  {
    outputFile << ' ' << arr[i];
  }
}
