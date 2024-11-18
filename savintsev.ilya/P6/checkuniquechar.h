
namespace savintsev
{
  bool isOneOfTheLetters(char c);
  bool isUnsignedInteger(const char * s, int & pos);
  bool isMultiplier(const char * s, int & pos);
  bool isTerm(const char* s, int & pos);
  bool isSignAdding(const char * str, const char ** endptr);
  bool isSignMultiplication(const char * str, const char ** endptr);
  bool isIdentifier(const char* s, int & pos);
  bool isStopSymbol(char c, const char ** endptr);
  bool isExpression(const char* s, int & pos);

}
