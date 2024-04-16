/**
 * @brief
 * @details
 */

#ifndef FUZZPP_RECORDER_H
#define FUZZPP_RECORDER_H
#include <vector>
#include <string>
#include <Windows.h>


class Recorder {
public:

    /**
     * getRuns() returns the number of times the program was run
     * @return An unsigned integer value
     */
    unsigned int getRuns();

    /**
     * getCrashes() returns the number of crashes recorded by this object
     * @return An unsigned integer value
     */
    unsigned int getCrashes();

    /**
     * getExceptions() returns the number of exceptions recorded by this object
     * @return An unsigned integer value
     */
    unsigned int getExceptions();

    /**
     * resetData() removes all data from previous records
     */
    void resetData();

    /**
     * record() logs any arguments which may have failed
     * @param arguments - A string pair of arguments which were passed to the program (e.g. "1 2")
     * @param status - The status of the program post-execution. Non-zero values indicate the program encountered a problem
     */
    void record(std::string arguments, DWORD status);

    /**
     * print the results of the recorded values
     */
    void printResults();


private:
    /**
     * incRuns() increments the number of times the program has been run
     */
    void incRuns();

    /**
     * incCrashes() increments the number of times the program has crashed
     */
    void incCrashes();

    /**
     * incExceptions() increments the number of times the program has encountered an exception
     */
    void incExceptions();
    unsigned int _runs = 0;
    unsigned int _crashes = 0;
    unsigned int _exceptions = 0;
    std::vector<std::string> _failedArgs;


};


#endif //FUZZPP_RECORDER_H
