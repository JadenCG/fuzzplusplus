/**
 * @file Executor.cpp
 * @brief Executor.cpp contains the implementations for the prototypes
 */

#include "Executor.h"

bool Executor::setPath(std::string path) {
    if(!isValidPath(path)) {
        _pathIsSet = false; //We'll set this to false so the user doesn't accidentally re-run previous code
        return false;
    }
    _filePath = path;
    _pathIsSet = true;
    return true;
}

bool Executor::isValidPath(std::string path) {
    if(std::filesystem::exists(path)) {
        return true;
    }
    return false;
}

bool Executor::runProgram(int *executionResult) {
    if(!_pathIsSet) {
        return false; //Don't execute if the path has not been updated properly
    }
    //TODO: running the program
    return true;
}