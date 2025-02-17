#include "stringProcessor.hpp"
#include <iostream>
#include <cstring>
#include <cctype>

char* excludeCharacters(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) {
        return nullptr;
    }

    char* result = new (std::nothrow) char[MAX_SIZE];
    if (result == nullptr) {
        std::cerr << "Ошибка: не удалось выделить память." << std::endl;
        exit(1);
    }

    size_t index = 0;
    for (size_t i = 0; str1[i] != '\0'; ++i) {
        bool found = false;
        for (size_t j = 0; str2[j] != '\0'; ++j) {
            if (str1[i] == str2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[index++] = str1[i];
        }
    }
    result[index] = '\0';

    return result;
}
