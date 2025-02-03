#include <iostream>
#include "stringProcessor.hpp"

int main() {
    const size_t MAX_SIZE = 1024;
    char input[MAX_SIZE];

    std::cout << "Введите строку: ";
    std::cin.getline(input, MAX_SIZE);

    const char* excludeStr = "aeiou";

    char* result = excludeCharacters(input, excludeStr);

    std::cout << "Результат: " << result << std::endl;

    delete[] result;

    return 0;
}
