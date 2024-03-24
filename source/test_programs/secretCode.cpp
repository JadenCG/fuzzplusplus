/**
 * @file secretCode.cpp
 * @brief secretCode is an example program which throws an exception if the provided arguments are specific values
 */
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        throw std::invalid_argument("Not enough arguments, please run as simpleinput 4 [value1] [value2] [value3] [value4]");
    }

    int first = (int) *argv[0];
    int second = (int) *argv[1];
    int third = (int) *argv[2];
    int fourth = (int) *argv[3];

    if(first == 4) {
        if(second == 1) {
            if(third == 2) {
                if(fourth == 3) {
                    throw std::invalid_argument("Found the secret code!");
                }
                std::cout << "rat" << std::endl;
                return 0;
            }
            std::cout << "bird" << std::endl;
            return 0;
        }
        std::cout << "dog" << std::endl;
        return 0;
    }
    std::cout << "cat" << std::endl;
    return 0;
}
