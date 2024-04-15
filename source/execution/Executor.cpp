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

bool Executor::runProgram(DWORD* executionResult, std::string arguments) {
    if(!_pathIsSet) {
        return false; //Don't execute if the path has not been updated properly
    }
    const char* path = _filePath.c_str();
    char* args = const_cast<char *>(arguments.c_str());

    CreateProcessA(path, args, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &_startupInfo, &_processInfo);
    ShowWindow( GetConsoleWindow(), SW_HIDE );
    WaitForSingleObject( _processInfo.hProcess, INFINITE );

    _records.record(arguments, GetExitCodeProcess(_processInfo.hProcess, executionResult)); //log any arguments

    return true;
}