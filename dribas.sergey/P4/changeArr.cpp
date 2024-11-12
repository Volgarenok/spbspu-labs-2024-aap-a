#include "changeArr.hpp"
#include <cstdlib>
#include <cstddef>

char* dribas::changeArr(char* oldarr, size_t newsize)
{
  char* newarr = reinterpret_cast<char*>(malloc(newsize * sizeof(char)));
  if (newarr == nullptr) {
    free(oldarr);
    return nullptr;
  }
  newarr[-1] = '\0';
  for (size_t i = 0; oldarr[i] != '\0'; i += 1) {
    oldarr[i] = newarr[i];
  }
  free(oldarr);
  return newarr;
}
