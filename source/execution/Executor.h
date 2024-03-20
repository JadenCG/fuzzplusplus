/**
 * @file Executor.h
 * @brief Executor maintains the file for the fuzzer to execute.
 */

#ifndef FUZZPP_EXECUTOR_H
#define FUZZPP_EXECUTOR_H

#include <string>
#include <stdexcept>
#include <filesystem>

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
     * runProgram() executes the program set through the setPath() method
     * @param executionResult - A pointer to an integer value. This will be used for the result of execution
     * @return - true if the program has run, false if the program has not been set or is improperly set
     */
    bool runProgram(int* executionResult);

private:
    std::string _filePath = "";
    bool _pathIsSet = false;
};


#endif //FUZZPP_EXECUTOR_H
