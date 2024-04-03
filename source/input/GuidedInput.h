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
    GuidedInput() = default;
    GuidedInput(bool setRecordValues);
    ~GuidedInput() = default;
    //No copy constructor

    int randInt();
    int randInt(int lowerBound, int upperBound);
    std::string makePair(int size);
    std::string makeBoundedPair(int size, int lowerBound, int upperBound);

private:
    bool recordValues = false;
    std::set<int> usedValues = std::set<int>();
};


#endif //FUZZPP_INPUT_H
