#include "count_digits.h"
#include <cctype>

int count_digits(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    return count;
}