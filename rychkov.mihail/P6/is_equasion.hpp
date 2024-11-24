#ifndef IS_EQUASION_CPP
#define IS_EQUASION_CPP

namespace rychkov
{
  bool isEquasion(const char* str);
  bool skipEquasion(const char** str);
  bool skipMultiplicationEquasion(const char** str);
  bool skipMultiplier(const char** str);
  bool skipVariable(const char** str);
  bool skipVariableLiteral(const char** str);
  bool skipUnsignedInt(const char** str);
  bool skipBinaryDigit(const char** str);
}

#endif
