/**
 * @file simpleInput.cpp
 * @brief simpleInput is a program which adds two numbers together
 * @details Under most instances, the value should return as expected. An exception occurs when both args are equal
 */

#include "simpleInput.h"
#include <string>
#include <stdexcept>

int main(int argc, char* argv[]) {
    int firstNumber = (int) *argv[0];
    int secondNumber = (int) *argv[1];

    if(firstNumber == secondNumber) {
        throw std::invalid_argument("both values are equal!");
    }
    else {
        printf("Returned value: %u", firstNumber + secondNumber);
    }
    return 0;
}