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
#include <Windows.h>

Recorder data = Recorder();
GuidedInput randomData = GuidedInput();
Executor execution = Executor();

int main() {
    std::string filePath;
    long fuzzingIters;

    std::cout << "Welcome to Fuzz Plus Plus!" << std::endl;
    std::cout << "Please input the path to the program to fuzz" << std::endl;

    while(true) { //allow the user multiple attempts to specify a path
        std::cin >> filePath; //TODO: limit arg to one string and check if it is whitespace
        if(filePath == "dev") { //shorthand for testing purposes
            filePath = "./simpleinput.exe";
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

    unsigned int currentIter = 0;
    STARTUPINFOA startupInfo;
    PROCESS_INFORMATION processInfo;
    std::string tempArguments = "2 2";

    const char * path = filePath.c_str();
    char * currentArgument = const_cast<char *>(tempArguments.c_str()); //May fail

    while (currentIter < fuzzingIters) {
        //TODO: refactor using executor object
        CreateProcessA(path, currentArgument, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &processInfo);
        try {
            int exitCode = -1;
            if (exitCode != 0) {
                data.incCrashes();
            }
        }
        catch (const std::exception ex) {
            data.incExceptions();
        }
        currentIter++;
    }

    std::cout << processInfo << std::endl;

    return 0;
}
