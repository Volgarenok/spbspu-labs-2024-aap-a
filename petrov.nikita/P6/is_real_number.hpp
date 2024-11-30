namespace petrov
{
  char * hasSign(char * str);
  char * hasSymbol(char * str, const char symbol);
  char * hasUnsignedInt(char * str);
  char * hasSignificand(char * str);
  char * hasOrderOfMagnitude(char * str);
  bool isRealNumber (char * str);
}