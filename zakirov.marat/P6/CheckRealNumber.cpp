#include "CheckRealNumber.hpp"
#include <cctype>

namespace
{
  const char * compare_literals(const char * line, char literal);
  const char * check_sign(const char * line);
  const char * check_integer(const char * line);
  const char * check_uinteger(const char * line);
  const char * check_sinteger(const char * line);
  const char * check_order(const char * line);
  const char * check_mantissa(const char * line);
  const char * check_end(const char * line);

  const char * compare_literals(const char * line, char literal)
  {
    if (!line)
    {
      return line;
    }

    if (*line == literal)
    {
      return ++line;
    }
    else
    {
      return nullptr;
    }
  }

  const char * check_sign(const char * line)
  {
    if (!line)
    {
      return line;
    }

    if (compare_literals(line, '+') || compare_literals(line, '-'))
    {
      return ++line;
    }
    else
    {
      return nullptr;
    }
  }

  const char * check_integer(const char * line)
  {
    if (!line)
    {
      return line;
    }

    if (std::isdigit(*line))
    {
      return ++line;
    }
    else
    {
      return nullptr;
    }
  }

  const char * check_uinteger(const char * line)
  {
    if (!line)
    {
      return line;
    }

    auto middle = check_integer(line);
    auto next = check_uinteger(middle);
    if (next)
    {
      return next;
    }
    else
    {
      return middle;
    }
  }

  const char * check_sinteger(const char * line)
  {
    if (!line)
    {
      return line;
    }

    auto next = check_sign(line);
    if (!next)
    {
      return check_uinteger(line);
    }
    else
    {
      return check_uinteger(next);
    }
  }

  const char * check_order(const char * line)
  {
    if (!line)
    {
      return line;
    }

    auto next = compare_literals(line, 'E');
    if (!next)
    {
      return next;
    }
    return check_sinteger(next);
  }

  const char * check_mantissa(const char * line)
  {
    if (!line)
    {
      return line;
    }

    auto next = compare_literals(line, '.');
    if (!next)
    {
      return check_uinteger(line);
    }
    return check_uinteger(next);
  }

  const char * check_end(const char * line)
  {
    if (!line)
    {
      return line;
    }

    if (*line == '\0')
    {
      return line;
    }
    else
    {
      return nullptr;
    }
  }
}

bool zakirov::check_real(const char * line)
{
  if (!line)
  {
    return line;
  }

  auto next = check_sign(line);
  if (!next)
  {
    auto middle = check_mantissa(line);
    auto full = check_order(middle);
    return check_end(full);
  }
  else
  {
    auto middle = check_mantissa(next);
    auto full = check_order(middle);
    return check_end(full);
  }
}
