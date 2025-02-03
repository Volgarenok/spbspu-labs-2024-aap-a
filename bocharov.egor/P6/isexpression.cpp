#include "isexpression.h"
#include <cctype>
#include <cstddef>
namespace
{
  bool isDigit(const char ** string, char cur);
  bool isLetter(const char ** string, char cur);
  bool hasId(const char ** string);
  bool hasNumber(const char ** string);
  bool hasMultiplier(const char ** string);
  bool hasTerm(const char ** string);

  bool isDigit(const char ** string, char cur)
  {
    if (cur == '9' + 1)
    {
      return 0;
    }
    if (cur == (**string))
    {
      ++(*string);
      return 1;
    }
    return isDigit(string, cur + 1);
  }

  bool isLetter(const char ** string, char cur)
  {
    if (cur == 'f')
    {
      return 0;
    }
    if (cur == (**string))
    {
      ++(*string);
      return 1;
    }
    return isLetter(string, cur + 1);
  }

  bool hasId(const char ** string)
  {
    char cur = 'a';
    return isLetter(string, cur);
  }

  bool hasNumber(const char ** string)
  {
    char cur = '0';
    bool result = isDigit(string, cur);
    if (result)
    {
      hasNumber(string);
    }
    return result;
  }

  bool hasMultiplier(const char ** string)
  {
    return hasNumber(string) || hasId(string);
  }

  bool hasTerm(const char ** string)
  {
    if (hasMultiplier(string))
    {
      if (**string == '*')
      {
        (*string)++;
        return hasTerm(string);
      }
      return true;
    }
    return false;
  }
}

bool bocharov::hasExpression(const char ** string)
{
  if (hasTerm(string))
  {
    if ((**string == '+') || (**string == '-'))
    {
      (*string)++;
      return hasExpression(string);
    }
    return true;
  }
  return false;
}

bool bocharov::isExpression(const char * string)
{
  return hasExpression(&string) && *string == '\0';
}
