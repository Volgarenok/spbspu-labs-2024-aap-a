#include "string_utils.hpp"
#include <iostream>
#include <string>

const char TO_REMOVE[] = "aeiou";

int main() {
    std::string input;
    std::getline(std::cin, input);

    char* result = beshimow::removeChars(input.c_str(), TO_REMOVE);
    if (result) {
        std::cout << "beshimow: " << result << std::endl;
        std::free(result);
    }

    return 0;
}
