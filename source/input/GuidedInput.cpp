/**
 * @file GuidedInput.cpp
 * @brief GuidedInput generates input for programs to run. Each value is returned as a string so it may be used in a program call
 */

#include "GuidedInput.h"


int GuidedInput::randInt() {
    int value = rand();
    if(recordValues) {
        usedValues.insert(value);
    }
    return value;
}

int GuidedInput::randInt(int lowerBound, int upperBound) {
    int value;
    if(upperBound != 0) {
         value = lowerBound + (rand() % upperBound);
    }
    else {
        value = 0;
    }

    if(recordValues) {
        usedValues.insert(value);
    }
    return value;
}

float GuidedInput::randFloat() {
    return (float) rand();
}

bool GuidedInput::randBool() {
    return (bool) (rand() % 2);
}

std::string GuidedInput::makeIntPair(int size) {
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
        }
        currentIndex++;
    }
    return currentString;
}

std::string GuidedInput::makeBoundedIntPair(int size, int lowerBound, int upperBound) {
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
        }
        currentIndex++;
    }
    return currentString;
}