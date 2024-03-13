/**
 * @file
 * @brief
 */

#include "Recorder.h"

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

void Recorder::incCrashes() {
    _crashes++;
}

void Recorder::incExceptions() {
    _exceptions++;
}