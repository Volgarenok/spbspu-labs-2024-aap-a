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

const char * check_uinteger(const char * line)
{
	if (!line)
	{
		return line;
	}

	auto next = zakirov::check_integer(line);
	if (next)
	{
		return zakirov::check_uinteger(next);
	}
	else
	{
		return zakirov::check_integer(line);
	}
}

const char * check_sinteger(const char * line)
{
	if (!line)
  {
    return line;
  }

	auto next = zakirov::check_sign(line);
	if (!next)
	{
		return zakirov::check_uinteger(line);
	}
	else
	{
		return zakirov::check_uinteger(next);
	}
}

