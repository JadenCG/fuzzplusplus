/**
 * @file
 * @brief
 */

#include "Recorder.h"

unsigned int Recorder::getCrashes() {
    return crashes;
}

unsigned int Recorder::getExceptions() {
    return exceptions;
}

void Recorder::resetData() {
    crashes = 0;
    exceptions = 0;
}

