#include "string_comparison.hpp"

int rychkov::cmpBegin(const char* lhs, const char* rhs)
{
  while ((*lhs != '\0') && (*rhs != '\0'))
  {
    if (*lhs != *rhs)
    {
      return *lhs - *rhs;
    }
    lhs++, rhs++;
  }
  return 0;
}
int rychkov::cmpEnd(const char* lhs, const char* rhs)
{
  const char* lhsEnd = lhs;
  const char* rhsEnd = rhs;
  while (*lhsEnd != '\0')
  {
    lhsEnd++;
  }
  while (*rhsEnd != '\0')
  {
    rhsEnd++;
  }

  while ((lhs != lhsEnd) && (rhs != rhsEnd))
  {
    if (*lhsEnd != *rhsEnd)
    {
      return *lhsEnd - *rhsEnd;
    }
    lhsEnd--, rhsEnd--;
  }
  return *lhsEnd - *rhsEnd;
}
