#include "string_utils.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

namespace beshimow {

char* removeChars(const char* str, const char* charsToRemove) noexcept {
    if (str == nullptr || charsToRemove == nullptr) {
        return nullptr;
    }

    size_t len = std::strlen(str);
    char* result = static_cast<char*>(std::malloc(len + 1));

    if (result == nullptr) {
        std::cerr << "Ошибка: не удалось выделить память." << std::endl;
        exit(1);
    }

    size_t index = 0;
    for (size_t i = 0; i < len; ++i) {
        bool found = false;
        for (size_t j = 0; charsToRemove[j] != '\0'; ++j) {
            if (str[i] == charsToRemove[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';

    return result;
}

}
