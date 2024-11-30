namespace petrov
{
  char * hasSign(char * str);
  char * hasSymbol(char * str, const char symbol);
  char * hasDigit(char * str);
  char * hasUnsignedInt(char * str);
  char * hasSignificand(char * str);
  char * hasOrderOfMagnitude(char * str);
  char * hasRealNumber(char * str);
  bool isRealNumber (char * str);
}
