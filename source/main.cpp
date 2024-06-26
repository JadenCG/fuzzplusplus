/**
 * @file main.cpp serves as the starting point for fuzzplusplus
 * @brief
 * @details
 */

//TODO: Console displays briefly on run
#include <iostream>
#include <string>
#include "input/GuidedInput.h"
#include "recorder/Recorder.h"
#include "execution/Executor.h"

Recorder data = Recorder();
GuidedInput randomData = GuidedInput();
Executor execution = Executor();

int main() {
    srand (time (NULL)); //should prevent generating identical numbers each run
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
        std::cin >> filePath;
        if(filePath == "dev") { //shorthand for testing purposes
            filePath = "./simpleinput.exe";
            execution.setPath("./simpleinput.exe");
        }
        if(filePath == "dev2") {
            filePath = "./secretcode.exe";
            execution.setPath("./secretcode.exe");
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
        if(upperBound >= lowerBound) {
            break; //One final check: are the bounds within an acceptable range?
        }
    }

    unsigned int currentIter = 0;
    DWORD exitCode;
    std::string tempArguments = "1 2";
    std::string arguments;

    while (currentIter < fuzzingIters) {
        if(numVals > 1) {
            if(useBounded) {
                arguments = randomData.makeBoundedIntPair(numVals, lowerBound, upperBound);
            }
            else {
                arguments = randomData.makeIntPair(numVals);
            }
        }
        try {
            execution.runProgram(&exitCode, arguments);
            execution.recordResult(exitCode, arguments);
        }
        catch (const std::exception ex) {

        }
        currentIter++;
    }

    execution.printResults();

    return 0;
}
