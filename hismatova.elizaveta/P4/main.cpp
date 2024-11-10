#include "fu_string.h"

int main()
{
  char str1 = hismatova::getline();
  char str2 = hismatoba::getline();
  if (str1 == nullptr || str2 == nullptr)
  {
    std::cerr << "run without input\n";
    return 1;
  }
  char * res = hismatova::uniqueChar(str1, str2);
  if (res != nullptr)
  {
    std::cout << res << "\n";
    free(res);
  }
  free(str1);
  free(str2);
}
