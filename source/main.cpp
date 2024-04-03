/**
 * @file main.cpp serves as the starting point for fuzzplusplus
 * @brief
 * @details
 */
#include <iostream>
#include <string>
#include "input/GuidedInput.h"
#include "recorder/Recorder.h"
#include "execution/Executor.h"

Recorder data = Recorder();
GuidedInput randomData = GuidedInput();
Executor execution = Executor();

int main() {
    std::string filePath;
    long fuzzingIters;
    std::string lowerBoundAsString;
    int numVals;
    int lowerBound;
    int upperBound;
    bool useBounded = false;

    std::cout << "Welcome to Fuzz Plus Plus!" << std::endl;
    std::cout << "Please input the path to the program to fuzz" << std::endl;

    while(true) { //allow the user multiple attempts to specify a path
        std::cin >> filePath; //TODO: limit arg to one string and check if it is whitespace
        if(filePath == "dev") { //shorthand for testing purposes
            filePath = "./simpleinput.exe";
            execution.setPath("./simpleinput.exe");
        }
        if(!execution.setPath(filePath)) {
            std::cout << "The provided file path is incorrect or missing" << std::endl;
        }
        else {
            break;
        }
    }

    while(true) { //allow the user to specify the number of iterations
        std::cout << "Please input the number of times to apply random values. This value may not be less than zero" << std::endl;
        std::cin >> fuzzingIters;
        if(fuzzingIters < 0) {
            std::cout << "The provided value is less than zero or invalid, please try again" << std::endl;
        }
        else {
            break;
        }
    }

    while(true) {
        std::cout << "Please enter the number of arguments the program should use." << std::endl;
        std::cin >> numVals;
        if(numVals >= 0) {
            break;
        }
    }

    while(true) {
        std::cout << "Please input the lower bound to fuzz by. If you do not want to set bounds, enter \"N/A\"" << std::endl;
        std::cin >> lowerBoundAsString;
        if(lowerBoundAsString == "N/A") {
            break; //cancel if lower bound is NA
        }
        useBounded = true;
        lowerBound = std::stoi(lowerBoundAsString);

        std::cout << "Please input the upper bound to fuzz by." << std::endl;
        std::cin >> upperBound;
        if(lowerBound < upperBound) {
            break; //One final check: are the bounds within an acceptable range?
        }
    }

    unsigned int currentIter = 0;
    DWORD exitCode;
    std::string tempArguments = "1 2";

    while (currentIter < fuzzingIters) {
        if(numVals > 1) {
            if(useBounded) {
                randomData.makeBoundedPair(numVals, lowerBound, upperBound);
            }
            else {
                randomData.makePair(numVals);
            }
        }
        try {
            execution.runProgram(&exitCode, tempArguments);
            if (exitCode != 0) {
                data.incCrashes();
            }
        }
        catch (const std::exception ex) {
            data.incExceptions();
        }
        currentIter++;
        std::cout << exitCode << std::endl;
    }

    return 0;
}
