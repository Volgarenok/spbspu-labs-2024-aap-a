#include <iostream>
#include <dynamic_string.h>
#include "string_utilities.h"

int main()
{
    constexpr int ratio = 2;
    size_t capacity = 10, size = 0;
    char* str = beshimow::get_string(std::cin, capacity, size, ratio, '\n');
    if (str == nullptr)
    {
        std::cerr << "Error: memory not allocate for string\n";
        return 1;
    }
    if (size == 0)
    {
        free(str);
        std::cerr << "Empty string\n";
        return 1;
    }
    std::cout << std::boolalpha << beshimow::is_double(str) << "\n";
    free(str);
}
