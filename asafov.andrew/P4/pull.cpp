#include <iostream>
#include "pull.h"
#include "resize.h"

void lab::pull(char*& a, size_t& lenght)
{
    size_t count = 8;
    a = new char[count];
    char g = 0;
    while (!std::cin.eof())
    {
        count--;
        std::cin >> g;
        if(std::cin.fail() || std::cin.eof())
        {
            break;
        }
        a[lenght] = g;
        lenght++;
        if (count == 0)
        {
            count = 8;
            a = lab::resize(a, lenght);
        }
    }
}
