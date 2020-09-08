// TextFileProcessor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "inputparameters.h"
#include "fileprocessor.h"
#include "dataprocessor.h"

int main(int argc, char* argv[])
{
    try {
        InputParams params;
        params.ParseInputString(argc, argv);
        FileProcessor reader(params.m_FileName);

        std::unique_ptr<DataProcessor> pProcessor;

        if (params.m_Mode == WORDS_MODE)
            pProcessor.reset(new WordFinderProcessor(params));
        else if (params.m_Mode == CHECKSUM_MODE)
            pProcessor.reset(new CheckSumProcessor);
        else
            throw std::string("ERROR: main: incorrect mode of execution");

        pProcessor->ProcessFileStream(reader.GetRefFileStream());
        pProcessor->PrintResult();
    }
    catch (std::string& e) {
        std::cout << e << std::endl;
        throw std::string("ERROR: main");
    }

    return 0;
}