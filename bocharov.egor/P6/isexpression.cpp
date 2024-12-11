#include "isexpression.h"
#include <cctype>
#include <cstddef>
namespace
{
  bool isDigit(const char ** string, char cur);
  bool isLetter(const char ** string, char cur);
  bool isId(const char ** string);
  bool isUnsigned_int(const char ** string);
  bool isMultiplier(const char ** string);
  bool isTerm(const char ** string);

  bool isDigit(const char ** string, char cur)
  {
    if (cur == '9' + 1)
    {
      return 0;
    }
    if (cur == (**string))
    {
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
      return 1;
    }
    return isLetter(string, cur + 1);
  }

  bool isId(const char ** string)
  {
    char cur = 'a';
    return isLetter(string, cur);
  }

  bool isUnsigned_int(const char ** string)
  {
    char cur = '0';
    bool result = isDigit(string, cur);
    if (result)
    {
      isUnsigned_int(string);
    }
    return result;
  }

  bool isMultiplier(const char ** string)
  {
    return isUnsigned_int(string) || isId(string);
  }

  bool isTerm(const char ** string)
  {
    if (isMultiplier(string))
    {
      if (**string == '*')
      {
        (*string)++;
        return isTerm(string);
      }
      return true;
    }
    return false;
  }
}

bool bocharov::isExpression(const char ** string)
{
  if (isTerm(string))
  {
    if ((**string == '+') || (**string == '-'))
    {
      (*string)++;
      return isExpression(string);
    }
    return true;
  }
  return false;
}

bool bocharov::Expression(const char * string)
{
  return isExpression(&string) && *string == '\0';
}
