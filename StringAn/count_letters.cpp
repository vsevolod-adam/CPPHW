#include "count_letters.h"
#include <cctype>

int count_letters(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            count++;
        }
    }
    return count;
}