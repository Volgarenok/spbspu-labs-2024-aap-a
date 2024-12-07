#include "mergeStrs.hpp"
#include <cstdlib>

char* maslovskiy::mergeStrs(const char* first, const char* second)
{
    size_t lenFirst = 0, lenSecond = 0;
    while (first[lenFirst] != '\0') ++lenFirst;
    while (second[lenSecond] != '\0') ++lenSecond;
    size_t resultSize = lenFirst + lenSecond + 1;
    char* result = reinterpret_cast<char*>(malloc(resultSize));
    if (!result)
    {
        return nullptr;
    }
    char* res = result;
    while (*first != '\0' && *second != '\0')
    {
        *res++ = *first++;
        *res++ = *second++;
    }
    while (*first != '\0')
    {
        *res++ = *first++;
    }
    while (*second != '\0')
    {
        *res++ = *second++;
    }
    *res = '\0';
    return result;
}
