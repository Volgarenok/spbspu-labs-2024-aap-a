#include <iostream>
#include <cstring>
#include <cctype>

namespace beshimow {
    void excludeCharacters(const char* str1, const char* str2, char*& result) {
        size_t len1 = std::strlen(str1);
        size_t len2 = std::strlen(str2);

        result = new char[len1 + 1];
        if (!result) {
            std::cerr << "Ошибка выделения памяти" << std::endl;
            exit(1);
        }

        size_t resultIndex = 0;

        for (size_t i = 0; i < len1; ++i) {
            bool shouldExclude = false;

            for (size_t j = 0; j < len2; ++j) {
                if (str1[i] == str2[j]) {
                    shouldExclude = true;
                    break;
                }
            }

            if (!shouldExclude) {
                result[resultIndex++] = str1[i];
            }
        }

        result[resultIndex] = '\0';
    }
}

int main() {

    char* input = nullptr;
    std::cout << "Введите строку: ";
    std::string temp;
    std::getline(std::cin, temp);

    input = new char[temp.length() + 1];
    if (!input) {
        std::cerr << "Ошибка выделения памяти" << std::endl;
        return 1;
    }
    std::strcpy(input, temp.c_str());

    const char* exclude = "abc";
    char* output = nullptr;

    beshimow::excludeCharacters(input, exclude, output);

    std::cout << output << std::endl;

    delete[] input;
    delete[] output;

    return 0;
}
