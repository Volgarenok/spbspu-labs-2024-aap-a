#include "vocab.h"

const char* demehin::hasLetter(const char* str)
{
  char letters[] = "ABCDE";
  if (!str)
  {
    return str;
  }

  bool isLetter = false;
  for (int i = 0; i < 5; ++i)
  {
    if (*str == letters[i])
    {
      isLetter = true;
      break;
    }
  }
  return (isLetter) ? (str + 1) : nullptr;
}

const char* demehin::hasNumber(const char* str)
{
  char numbers[] = "0123456789";
  if (!str)
  {
    return str;
  }

  bool isNumber = false;
  for (int i = 0; i < 10; ++i)
  {
    if (*str == numbers[i])
    {
      isNumber = true;
      break;
    }
  }
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

