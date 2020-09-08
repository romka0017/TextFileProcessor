# Text file processor
Current project includes shared library, unit tests based on "Catch" framework and main program for working with the input text file.
Library supports 2 modes:

First mode: finding of the occurrences for the needed word.

Second mode: calculation of the 32bit checksum based on algorithm: checksum = word1 + word2 + ... + wordN

## Dependencies
Framework for unit tests [Catch] (https://github.com/catchorg/Catch2)

## Structure
Library includes classes for input parameters processing, input file processing and data processing.

**/include/dataprocessor.h**

**/include/fileprocessor.h**

**/include/inputparameters.h**

**/src/dataprocessor.cpp**

**/src/fileprocessor.cpp**

**/src/inputparameters.cpp**

Unit tests include "catch.hpp" header file and "catch_tests.cpp" source file

**/libs/catch.hpp**

**/test/catch_tests.cpp**

Main program includes "TextFileProcessor.cpp" source file

**/program/TextFileProcessor.cpp**

## How to build
To build the project you should use cmake 3.16+ and GCC 6+.

You can build a separate shared library or you can build tests/main program which will
use pre-built library.

To build the library only please run "cmake ~pwd" from "FileProcessor/src" folder.
To build the tests + library please run "cmake ~pwd" from "FileProcessor/test" folder.
To build the main program + library please run "cmake ~pwd" from "FileProcessor/program" folder.

## Tests
To run the tests please run executable file "catch_tests".
