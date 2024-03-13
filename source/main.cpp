/**
 * @file main.cpp serves as the starting point for fuzzplusplus
 * @brief
 * @details
 */
#include <iostream>
#include <string>
#include "/input/GuidedInput.h"
#include "/recorder/Recorder.h"
#include "execution/Executor.h"

Recorder data = Recorder();
GuidedInput randomData = GuidedInput();
Executor execution = Executor();

int main() {
    std::string filePath;
    unsigned int fuzzingIters;

    std::cout << "Welcome to Fuzz Plus Plus!" << std::endl;
    std::cout << "Please input the path to the program to fuzz" << std::endl;

    while(true) { //allow the user multiple attempts to specify a path
        std::cin >> filePath;
        if(!execution.setPath(filePath)) {
            std::cout << "The provided file path is incorrect or missing" << std::endl;
        }
        else {
            break;
        }
    }

    std::cout << "Please input the number of times to apply random values. This value may not be less than zero." << std::endl;
    std::cin >> fuzzingIters;

    unsigned int currentIter = 0;
    while (currentIter < fuzzingIters) {
        //TODO: refactor using executor object
        try {
            int exitCode = -1;
            if(exitCode != 0) {
                data.incCrashes();
            }
        }
        catch(const std::exception ex) {
            data.incExceptions();
        }
    }


    
    return 0;
}
