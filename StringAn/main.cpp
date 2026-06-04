#include <iostream>
#include <string>
#include <cstring>
#include "count_digits.h"
#include "count_letters.h"
#include "to_upper.h"

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int digitCount = count_digits(input.c_str());
    int letterCount = count_letters(input.c_str());

    char* mutableStr = new char[input.length() + 1];
    strcpy(mutableStr, input.c_str());
    to_upper(mutableStr);

    std::cout << "Original string: " << input << std::endl;
    std::cout << "Number of digits: " << digitCount << std::endl;
    std::cout << "Number of letters: " << letterCount << std::endl;
    std::cout << "Uppercase string: " << mutableStr << std::endl;

    delete[] mutableStr;

    return 0;
}