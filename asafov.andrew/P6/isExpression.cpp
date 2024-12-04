#include "isExpression.hpp"

bool isBetween(char term1, char term2, char term3)
{
    if(term1 == term2)
    {
        return true;
    }
    else if(term2 == term3)
    {
        return false;
    }
    term2++;
    isBetween(term1, term2, term3);
}

bool isDigit(char term)
{
    if(isBetween(term, '0', '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isLetter(char term)
{
    if(isBetween(term, 'a', 'z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool asafov::isExpression(char* string, unsigned long long pos, unsigned long long length)
{
    if(isDigit(string[pos]))
    {
        if(isDigit(string[pos + 1]))
        {
            return isExpression(string, pos + 1, length);
        }
        else if(isLetter(string[pos + 1]))
        {
            return isExpression(string, pos + 1, length);
        }
        else if(string[pos + 1]=='*')
        {
            return isExpression(string, pos + 1, length);
        }
        else if(string[pos + 1]=='+' || string[pos + 1]=='-')
        {
            return isExpression(string, pos + 1, length);
        }
        else if(pos + 1 == length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(isLetter(string[pos]))
    {
        if(string[pos + 1]=='*')
        {
            return isExpression(string, pos + 1, length);
        }
        else if(string[pos + 1]=='+' || string[pos + 1]=='-')
        {
            return isExpression(string, pos + 1, length);
        }
        else if(pos + 1 == length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(string[pos] == '*')
    {
        if(isDigit(string[pos + 1]))
        {
            return isExpression(string, pos + 1, length);
        }
        else if(isLetter(string[pos + 1]))
        {
            return isExpression(string, pos + 1, length);
        }
        else
        {
            return false;
        }
    }
    else if(string[pos] == '+' || string[pos]=='-')
    {
        if(isDigit(string[pos + 1]))
        {
            return isExpression(string, pos + 1, length);
        }
        else if(isLetter(string[pos + 1]))
        {
            return isExpression(string, pos + 1, length);
        }
        else
        {
            return false;
        }
    }
    return true;
}
