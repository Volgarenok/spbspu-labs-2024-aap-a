#include "CheckRealNumber.hpp"

const char * zakirov::compare_literals(const char * line, char literal)
{
	  if (!line)
  	{
    	return line;
  	}

		return (* line == literal) ? (line + 1) : nullptr;
}

const char * zakirov::check_sign(const char * line)
{
	if (!line)
  {
    return line;
  }

	if (compare_literals(line, '+') || compare_literals(line, '-'))
	{
		return line + 1;
	}
	else
	{
		return nullptr;
	}
}

const char * zakirov::check_integer(const char * line)
{
	if (!line)
  {
    return line;
  }

	return (* line >= '0' && * line <= '9') ? (line + 1) : nullptr;
}
