/**
 * @file GuidedInput.cpp
 * @brief GuidedInput generates input for programs to run. Each value is returned as a string so it may be used in a program call
 */

#include "GuidedInput.h"


std::string GuidedInput::randInt() {
    srand(time(NULL));
    int value = rand();
    if(recordValues) {
        usedValues.insert(value);
    }
    return std::to_string(value);
}

std::string GuidedInput::randInt(int lowerBound, int upperBound) {
    srand(time(NULL));
    int value = lowerBound + (rand() % upperBound);
    if(recordValues) {
        usedValues.insert(value);
    }
    return std::to_string(value);
}