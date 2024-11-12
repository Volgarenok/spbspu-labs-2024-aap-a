#include "changeArr.hpp"
#include <cstdlib>
#include <cstddef>

char* dribas::changeArr(char* oldarr, size_t newsize)
{
  char* newarr = static_cast<char*>(malloc(newsize * sizeof(char)));
  if (newarr == nullptr) {
    free(oldarr);
    return nullptr;
  }
  for (size_t i = 0; i < newsize; i += 1) {
    newarr[i] = '0';
  }
  newarr[newsize - 1] = '\0';
  for (size_t i = 0; oldarr[i] != '\0'; i += 1) {
    newarr[i] = oldarr[i];
  }
  free(oldarr);
  return newarr;
}
