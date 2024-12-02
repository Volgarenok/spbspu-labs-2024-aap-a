#include "validNumber.h"
#include <cctype>

namespace cherkasov
{
  const char* locateSymbol(const char* str, char symbol);
  const char* identifySign(const char* str);
  const char* checkDigit(const char* str);
  const char* readUnsignedInt(const char* str);
  const char* readExponent(const char* str);
  const char* readFraction(const char* str);
  const char* recognizeRealNumber(const char* str);
}

const char* cherkasov::locateSymbol(const char* str, char symbol)
{
  return (str && *str == symbol) ? (str + 1) : nullptr;
}

const char* cherkasov::identifySign(const char* str)
{
  return locateSymbol(str, '+') ? locateSymbol(str, '+') : locateSymbol(str, '-');
}

const char* cherkasov::checkDigit(const char* str)
{
  return (str && std::isdigit(*str)) ? (str + 1) : nullptr;
}

const char* cherkasov::readUnsignedInt(const char* str)
{
  auto next = checkDigit(str);
  return next ? readUnsignedInt(next) : str;
}

const char* cherkasov::readExponent(const char* str)
{
  auto next = locateSymbol(str, 'E');
  if (next)
  {
    next = identifySign(next);
    return readUnsignedInt(next);
  }
  return str;
}

const char* cherkasov::readFraction(const char* str)
{
  auto next = readUnsignedInt(str);
  if (next)
  {
    next = locateSymbol(next, '.');
    return readUnsignedInt(next);
  }
  return str;
}

const char* cherkasov::recognizeRealNumber(const char* str)
{
  auto next = identifySign(str);
  if (next)
  {
    next = readFraction(next);
    return readExponent(next);
  }
  return readExponent(readFraction(str));
}

bool cherkasov::validateRealNumber(const char* str)
{
  auto result = recognizeRealNumber(str);
  return result && *result == '\0';
}
