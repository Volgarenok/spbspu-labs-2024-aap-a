#include <iostream>
#include <fstream>


std::istream & inputMatrix(std::istream & in, int * t, size_t m, size_t n)
{
  size_t size_table = n * m;
  for (size_t i = 0; i < size_table; ++i)
  {
    in >> t[i];
  }
  return in;
}


void output(std::ostream & out, int * t, size_t m, size_t n)
{
  int max_count_diag = m + n - 1;
  int sums[max_count_diag] = {0};
  int diag_count[max_count_diag] = {0};
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      int index_diag = j - (m - i - 1);
      sums[index_diag] += table[i * n + j];
      diag_count[index_diag]++;
    }
  }
int min_sum = std::numeric_limits<int>::max();
for (size_t i = 0; i < max_count_diag; ++i)
{
  if (diag_count[i] > 0 && sums[i] < min_sum)
  {
    min_sum = sums[i];
  }
}
std::ofstream output(argv[3]);
output << min_sum << "\n";
}


int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Incorrect amount of data entered" << "\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoi(argv[1]);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Invalid num" << "\n";
    return 1;
  }
  if (num != 1 || num != 2)
  {
    std::cerr << "Invalid value num" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!(input >> m >> n) || m == 0 || n == 0)
  {
    std::cerr << "Invalid table size data" << "\n";
    return 2;
  }
  if (num == 1)
  {
    int table[1000];
    inputMatrix(input, table, m, n);
    if (!(input_matrix(input, table, m, n)))
    {
      std::cerr << "Invalid input" << "\n";
      return 2;
    }
    outputMatrix(output, table, m, n);
  }
  else
  {
    int * table = new int[m * n];
    input_matrix(input, table, m, n);
    if (!(input_matrix(input, table, m, n)))
    {
      std::cerr << "Invalid input" << "\n";
      delete[] table;
      return 2;
    }
    outputMatrix(output, table, m, n);
    delete[] table;
  }
  return 0;
}


