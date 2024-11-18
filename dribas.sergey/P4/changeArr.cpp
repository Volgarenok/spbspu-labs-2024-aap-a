#include "changeArr.hpp"
#include <cstdlib>
#include <cstddef>

char* dribas::changeArr(char* oldarr, size_t newsize)
{
  char* newarr = static_cast< char* >(malloc(newsize * sizeof(char)));
  if (newarr == nullptr) {
    free(oldarr);
    return nullptr;
  }
  if (newsize > 2) {
    for (size_t i = 0; oldarr[i] != '\0'; i += 1) {
      newarr[i] = oldarr[i];
    }
  }
  newarr[newsize-1] = '\0';
  free(oldarr);
  return newarr;
}
