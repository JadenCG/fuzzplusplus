/**
 * @file GuidedInput.cpp
 * @brief GuidedInput generates input for programs to run. Each value is returned as a string so it may be used in a program call
 */

#include "GuidedInput.h"


int GuidedInput::randInt() {
    srand(time(NULL));
    int value = rand();
    if(recordValues) {
        usedValues.insert(value);
    }
    return value;
}

int GuidedInput::randInt(int lowerBound, int upperBound) {
    srand(time(NULL));
    int value = lowerBound + (rand() % upperBound);
    if(recordValues) {
        usedValues.insert(value);
    }
    return value;
}

std::string GuidedInput::makePair(int size) {
    if(size <= 0) {
        return "";
    }
    int items[size];
    int currentIndex = 0;
    std::string currentString = "";
    while(currentIndex < size) {
        if(currentIndex == size - 1) {
            currentString += std::to_string(randInt());
        }
        else {
            currentString += std::to_string(randInt()) + " ";
            currentIndex++;
        }
    }
    return currentString;
}

std::string GuidedInput::makeBoundedPair(int size, int lowerBound, int upperBound) {
    if(size <= 0) {
        return "";
    }
    int items[size];
    int currentIndex = 0;
    std::string currentString = "";
    while(currentIndex < size) {
        if(currentIndex == size - 1) {
            currentString += std::to_string(randInt(lowerBound, upperBound));
        }
        else {
            currentString += std::to_string(randInt(lowerBound, upperBound)) + " ";
            currentIndex++;
        }
    }
    return currentString;
}