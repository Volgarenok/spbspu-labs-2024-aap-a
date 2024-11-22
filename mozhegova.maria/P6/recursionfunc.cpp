#include "recursionfunc.hpp"

const char * mozhegova::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : nullptr;
}

const char * mozhegova::hasNumber(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
}

const char * mozhegova::hasIdentifier(const char * str)
{
  return mozhegova::hasLetter(str);
}

const char * mozhegova::hasUnsignedInt(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasNumber(str);
  if (auto continues = mozhegova::hasUnsignedInt(next))
  {
    return continues;
  }
  return next;
}
