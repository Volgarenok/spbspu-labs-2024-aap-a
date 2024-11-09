#include <fstream>
#include "func.hpp"

void matrixPush(int n, char* output)
{
  std::ofstream fout(output);
  fout << n;
  fout.close();
}
