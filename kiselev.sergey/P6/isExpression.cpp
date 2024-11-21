#include "isExpression.h"
const char* isX(const char* string)
{
  if (!string)
  {
    return string;
  }
  return (*string == 'x') ? (string + 1) : nullptr;
}
const char* isY(const char* string)
{
  if (!string)
  {
    return string;
  }
  return (*string == 'y') ? (string + 1) : nullptr;
}
const char* isZ(const char* string)
{
  if (!string)
  {
    return string;
  }
  return (*string == 'z') ? (string + 1) : nullptr;
}
bool kiselev::isExpression(const char* string)
{
  return true;
}

