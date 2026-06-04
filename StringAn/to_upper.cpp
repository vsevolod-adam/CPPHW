#include "to_upper.h"
#include <cctype>

void to_upper(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}