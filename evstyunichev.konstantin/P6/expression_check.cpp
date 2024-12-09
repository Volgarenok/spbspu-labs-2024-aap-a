#include "expression_check.hpp"

namespace
{
  const char * is_factor_correct(const char *, int prevState = 3);
  const char * is_term_correct(const char *, bool prev = 1);
  const char * is_expression_correct(const char *, bool prev = 1, bool isBracketOpened = 0);
  bool is_letter(char, char cur = 'a');
  bool is_digit(char, char cur = '0');
  bool is_basic_symbol(char);
  bool is_sign(char);

  const char * is_factor_correct(const char *p, int prevState)
  {
    if (p == nullptr)
    {
      return nullptr;
    }
    int cur = 4;
    if (is_letter(*p))
    {
      cur = (prevState == 3);
    }
    if (is_digit(*p))
    {
      cur = 2 & prevState;
    }
    if (cur & 4)
    {
      return p;
    }
    if (cur)
    {
      return is_factor_correct(++p, cur);
    }
    return nullptr;
  }

  const char * is_term_correct(const char *p, bool prev)
  {
    if (!p)
    {
      return p;
    }
    if (is_basic_symbol(*p))
    {
      return is_term_correct(is_factor_correct(p), 0);
    }
    if (*p == '(')
    {
      p++;
      p = is_expression_correct(p, 1, 1);
      if (!p)
      {
        return p;
      }
      if (*p != ')')
      {
        return nullptr;
      }
      p++;
      return is_term_correct(p, 0);
    }
    if (prev)
    {
      return nullptr;
    }
    if (*p == '*')
    {
      return is_term_correct(++p);
    }
    return p;
  }

  const char * is_expression_correct(const char *p, bool prev, bool isBracketOpened)
  {
    if (p == nullptr)
    {
      return nullptr;
    }
    if (is_basic_symbol(*p))
    {
      return is_expression_correct(is_term_correct(p), 0, isBracketOpened);
    }
    if (*p == '(')
    {
      return is_term_correct(p);
    }
    if (prev)
    {
      return nullptr;
    }
    if (is_sign(*p))
    {
      return is_expression_correct(++p, 1, isBracketOpened);
    }
    if (*p == 0)
    {
      return p;
    }
    if (isBracketOpened && (*p == ')'))
    {
      return p;
    }
    return nullptr;
  }

  bool is_letter(char c, char cur)
  {
    if (cur == 'z' + 1)
    {
      return 0;
    }
    if (cur == c)
    {
      return 1;
    }
    if (cur == 'f')
    {
      return is_letter(c, 'x');
    }
    return is_letter(c, cur + 1);
  }

  bool is_digit(char c, char cur)
  {
    if (cur == '9' + 1)
    {
      return 0;
    }
    if (cur == c)
    {
      return 1;
    }
    return is_digit(c, cur + 1);
  }

  bool is_basic_symbol(char c)
  {
    return (is_digit(c) || is_letter(c));
  }

  bool is_sign(char c)
  {
    return ((c == '+') || (c == '-'));
  }
}

bool evstyunichev::check_expression(const char *str)
{
  return (is_expression_correct(str) != nullptr);
}
