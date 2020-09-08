#ifndef __INPUT_PARAMETERS_H__
#define __INPUT_PARAMETERS_H__

#include <cstring>
#include <string>
#include <iostream>

// Mode
enum {
    UNDEFINED_MODE = 0,
    WORDS_MODE     = 1,
    CHECKSUM_MODE  = 2
};

class InputParams
{
public:

    int ParseInputString(int argc, char* argv[]);

    unsigned char m_Mode = UNDEFINED_MODE;
    std::string   m_FileName;
    std::string   m_NeededWord;

private:

    std::string GetStringArgument(char* argv[], unsigned char index, int nArgNum);


    bool m_bPrintHelp = false;
};


#endif // __INPUT_PARAMETERS_H__
