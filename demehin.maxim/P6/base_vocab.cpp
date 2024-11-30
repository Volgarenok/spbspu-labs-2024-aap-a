#include "vocab.h"

const char* demehin::hasLetter(const char* str)
{
  if (!str)
  {
    return str;
  }

  bool isLetter = *str >= 'A' && *str <= 'E';
  return (isLetter) ? (str + 1) : nullptr;
}

const char* demehin::hasNumber(const char* str)
{
  if (!str)
  {
    return str;
  }

  bool isNumber = *str >= '0' && *str <= '9';
  return (isNumber) ? (str + 1) : nullptr;
}

const char* demehin::hasIdent(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  return demehin::hasLetter(str);
}

const char* demehin::hasUInt(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = demehin::hasNumber(str);
  return demehin::hasNumber(next);
}

