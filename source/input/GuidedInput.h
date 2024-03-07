/**
 * @file GuidedInput.h
 * @brief GuidedInput.h contains the prototypes for functions in the GuidedInput class
 */

#ifndef FUZZPP_INPUT_H
#define FUZZPP_INPUT_H
#include <string>
#include <set>
#include <time.h>


class GuidedInput {
public:
    GuidedInput();
    GuidedInput(bool setRecordValues);
    ~GuidedInput();
    //No copy constructor

    std::string randInt();
    std::string randInt(int lowerBound, int upperBound);

private:
    bool recordValues = false;
    std::set<int> usedValues = std::set<int>();
};


#endif //FUZZPP_INPUT_H
