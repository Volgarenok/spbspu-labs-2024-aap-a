#include "isExpression.hpp"

bool asafov::isBetween(char letter, char begin, char end)
{
  return (begin != end) ? (letter != begin ? isBetween(letter, ++begin, end) : letter == begin) : (begin != end);
}

bool asafov::isDigit(char term)
{
  return isBetween(term, '0', '9');
}

bool asafov::isLetter(char term)
{
  return isBetween(term, 'a', 'z');
}

bool asafov::isLastSym(size_t pos, size_t length, const char* string)
{
  if (pos + 1 == length){
    return true;
  }
  return isExpression(string, pos + 1, length);
}

bool asafov::isExpression(const char* string, size_t pos, size_t length)
{
  if (isDigit(string[pos]))
  {
    if (isDigit(string[pos + 1]))
    {
      return isLastSym(pos, length, string);
    }
    else if (isLetter(string[pos + 1]))
    {
      return isLastSym(pos, length, string);
    }
    else if (string[pos + 1] == '*')
    {
      return isExpression(string, pos + 1, length);
    }
    else if (string[pos + 1] == '+' || string[pos + 1] == '-')
    {
      return isExpression(string, pos + 1, length);
    }
    else
    {
      return false;
    }
  }
  else if (isLetter(string[pos]))
  {
    if (string[pos + 1] == '*')
    {
      return isExpression(string, pos + 1, length);
    }
    else if (string[pos + 1] == '+' || string[pos + 1] == '-')
    {
      return isExpression(string, pos + 1, length);
    }
    else
    {
      return false;
    }
  }
  else if (string[pos] == '*')
  {
    if (isDigit(string[pos + 1]))
    {
      return isLastSym(pos, length, string);
    }
    else if (isLetter(string[pos + 1]))
    {
      return isLastSym(pos, length, string);
    }
    else
    {
      return false;
    }
  }
  else if (string[pos] == '+' || string[pos] == '-')
  {
    if (isDigit(string[pos + 1]))
    {
      return isLastSym(pos, length, string);
    }
    else if (isLetter(string[pos + 1]))
    {
      return isLastSym(pos, length, string);
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}
