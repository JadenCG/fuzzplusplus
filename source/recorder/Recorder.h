/**
 * @brief
 * @details
 */

#ifndef FUZZPP_RECORDER_H
#define FUZZPP_RECORDER_H


class Recorder {
public:
    unsigned int getCrashes();
    unsigned int getExceptions();
    void resetData();
    void restartProgram(int argc, char* argv); //TODO: address?


private:
    unsigned int crashes = 0;
    unsigned int exceptions = 0;


};


#endif //FUZZPP_RECORDER_H
