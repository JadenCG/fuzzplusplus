# Fuzz Plus Plus
Fuzz Plus Plus is a simple fuzzer written in C++ for Cs5110  Software Verification.

## About

Fuzz++ is a simple fuzzing program written in C++ for the University of Utah's Software Verification class. The project builds exclusively on Windows Machines.

The fuzzer will test a pre-built executable with random inputs. These values and other properties are configured by the user upon executing the program. Following this, the results of the execution are displayed, including any parameters which have thrown an exception

Two test program can be built as well. SimpleInput accepts two values and will throw an exception if both values are equal. SecretCode accepts four values and will throw an exception if the provided input is "4 1 2 3".

## Building

1. Clone the repository and open it using a C++ IDE. 
2. Import the provided CMakeLists file as needed
3. Build FuzzPlusPlus using its associated configuration. If you wish to use the provided tests, you will need to run the build configuration for these as well.
