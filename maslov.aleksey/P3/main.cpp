#include <iostream>
#include <fstream>
#include <cstdlib>

std::istream & inputMatrix(std::istream & in, int** t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      in >> t[i][j];
    }
    ++read;
  }
  return in;
}
int * convert(const int* const* t, size_t m, size_t n)
{
  int array[10000];
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      array[i * n + j] = t[i][j];
    }
  }
  return array;
}
void destroy(int** theMatrix, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] theMatrix[i];
  }
  delete[] theMatrix;
}

int** createMatrix(size_t m, size_t n)
{
  int** theMatrix = new int*[m];
  size_t created = 0;
  try
  {
    for(; created < m; ++created)
    {
      theMatrix[created] = new int[n];
    }
  }
  catch(const std::bad_alloc & e)
  {
    destroy(theMatrix, created);
    throw;
  }
  return theMatrix;
}
void outputMatrix(std::ostream &out);

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
  char* endptr = nullptr;
  long taskNumber = std::strtol(argv[1], &endptr, 10);
  if (endptr != "\0")
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if(!(taskNumber == 1 || taskNumber == 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  size_t m = 10, n = 10;
  size_t read = 0;
  int ** t = nullptr;
  try
  {
    t = createMatrix(m,n);
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  try
  {
    std::cin.exceptions(std::ios::failbit | std::ios::badbit); 
    inputMatrix(std::cin, t, m, n, read);
  }
  catch (const std::ios_base::failure & e)
  {
    std::cerr << "" << e.what() << "\n";
    return 1;
  }
  if (taskNumber == 1)
  {
    convert(t, m, n);
    destroy(t,m);
  }
  else
  {
  }
  std::ofstream output(argv[3]);
  outputMatrix(output);
}
