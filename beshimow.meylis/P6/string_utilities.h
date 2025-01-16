#ifndef STRING_UTILITIES_H
#define STRING_UTILITIES_H

namespace beshimow {
    bool is_double(const char* str);
    char* get_string(std::istream& input, size_t& capacity, size_t& size, int ratio, char delimiter);
}

#endif // STRING_UTILITIES_H
