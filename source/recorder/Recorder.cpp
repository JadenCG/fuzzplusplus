/**
 * @file
 * @brief
 */

#include <iostream>
#include "Recorder.h"

unsigned int Recorder::getRuns() {
    return _runs;
}

unsigned int Recorder::getCrashes() {
    return _crashes;
}

unsigned int Recorder::getExceptions() {
    return _exceptions;
}

void Recorder::resetData() {
    _crashes = 0;
    _exceptions = 0;
}

void Recorder::record(std::string arguments, DWORD status) {
    if(status != 0) { //any nonzero status indicates a crash/exception
        incExceptions();
        _failedArgs.push_back(arguments);
    }
    incRuns();
}

void Recorder::incRuns() {
    _runs++;
}

void Recorder::incCrashes() {
    _crashes++;
}

void Recorder::incExceptions() {
    _exceptions++;
}

void Recorder::printResults() {
    std::cout << "Total runs: ";
    std::cout << getRuns() << std::endl;
    std::cout << "Total exceptions: ";
    std::cout << getExceptions() << std::endl;
    std::cout << "Arguments which caused exceptions: " << std::endl;
    if(_failedArgs.empty()) {
        std::cout << "None!" << std::endl;
    }
    else {
        int currentIndex = 0;
        while(currentIndex != _failedArgs.size()) {
            std::cout << _failedArgs[currentIndex] << std::endl;
            currentIndex++;
        }
    }
}