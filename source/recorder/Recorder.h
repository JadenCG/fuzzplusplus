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
    void incCrashes();
    void incExceptions();


private:
    unsigned int _crashes = 0;
    unsigned int _exceptions = 0;


};


#endif //FUZZPP_RECORDER_H
