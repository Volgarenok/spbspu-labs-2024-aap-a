namespace smirnov
{
  const char * isSymbol(const char * string, char c);
  const char * isSigh(const char * string);
  const char * isNumber(const char * string);
}

const char * smirnov::isSymbol(const char * string, char c)
{
  if (!string)
  {
    return string;
  }
  return (*string == c) ? (string + 1) : nullptr;
}

const char * smirnov::isSign(const char * string)
{
  if (!string)
  {
    return string;
  }
  return (isSymbol(string, '+') || isSymbol(string, '-')) ? (string + 1) : nullptr;
}

const char * smirnov::isNumber(const char * string)
{
  if (!string)
  {
    return string;
  }
  return (*string >= '0' && *string <= '9') ? (string + 1) : nullptr;
}
