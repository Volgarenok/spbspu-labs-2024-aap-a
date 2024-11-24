#include "isExpression.hpp"

unsigned char isExpression(char* string, unsigned long long pos, unsigned long long lenght, unsigned char step)
{
    unsigned long long len = 0;
    if(step == 0)
    {
        for(unsigned long long i = pos; i < lenght; i++)
        {
            if(string[i] == '+' || string[i] == '-')
            {
                if(isExpression(string, i-len,i, 1)!=1)
                {
                    return 2;
                }
                len=0;
            }
            else
            {
                len++;
            }
        }
        if(isExpression(string, lenght - len, lenght, 1)!=1)
        {
            return 2;
        }
        return 1;
    }
    else if(step == 1)
    {
        len=0;
        for(unsigned long long i = pos; i < lenght; i++)
        {
            if(string[i] == '*')
            {
                if(isExpression(string, i-len,i, 2)!=1)
                {
                    return 2;
                }
                len=0;
            }
            else
            {
                len++;
            }
            if(isExpression(string, lenght - len, lenght, 2)!=1)
            {
                return 2;
            }
            return 1;
        }
    }
    else if(step == 2)
    {
        if(isExpression(string, lenght, lenght, 3)!=1)
        {
            for(unsigned long long i = pos; i < lenght; i++)
            {
                if(isExpression(string, i, i, 4)!=1)
                {
                    return 2;
                }
            }
        }
        else
        {
            return 2;
        }
        return 1;
    }
    else if(step==3)
    {
        if(string[lenght-1] >= 'a' && string[lenght-1] <= 'e')
        {
            return 1;
        }
        else if(string[lenght] >=0 && string[lenght] <=9)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else if(step==4)
    {
        if(string[lenght] >=0 && string[lenght] <=9)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}
