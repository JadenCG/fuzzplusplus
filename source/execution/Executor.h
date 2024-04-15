/**
 * @file Executor.h
 * @brief Executor maintains the file for the fuzzer to execute.
 */

#ifndef FUZZPP_EXECUTOR_H
#define FUZZPP_EXECUTOR_H

#include <string>
#include <stdexcept>
#include <filesystem>
#include <Windows.h>
#include "../recorder/Recorder.h"

class Executor {
public:
    Executor() = default;
    ~Executor() = default;

    /**
     * setPath() sets the path of the file for the executor to run
     * @param path - The path to the desired program
     * @return - true if the value is valid and set, otherwise false is returned
     */
    bool setPath(std::string path);

    /**
     * isValidPath() determines whether the provided path is valid for the executor to run
     * @param path - The path to the desired program
     * @return - true if the path exists, otherwise false is returned
     */
    bool isValidPath(std::string path);

    /**
     * runProgram() executes the program which the Executor has been initialized with
     * @param executionResult - A DWORD object pointer; used as a secondary return value
     * @param arguments - The arguments to run the program with
     * @return - TRUE if the method completed without issues, otherwise FALSE is returned
     */
    bool runProgram(DWORD* executionResult, std::string arguments);

    /**
     * printResults() outputs the results of execution. If no crashing data was recorded, a message indicating so will
     * display
     */
    void printResults();

private:
    std::string _filePath = "";
    bool _pathIsSet = false;
    STARTUPINFOA _startupInfo;
    PROCESS_INFORMATION _processInfo;
    Recorder _records;
};


#endif //FUZZPP_EXECUTOR_H
