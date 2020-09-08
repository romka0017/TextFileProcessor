#include "inputparameters.h"

void PrintHelp()
{
    printf("Usage:\n");
    printf(" First mode:-f [input_file_name] -m words -v [needed_word]\n");
    printf(" Mode prints number of occurrences of the [needed_word] in the input file\n");
    printf(" Second mode:-f [input_file_name] -m checksum\n");
    printf(" Mode prints 32bit checksum of the input file based on algorithm: checksum = word1 + word2 + ... + wordN\n");
}

int InputParams::ParseInputString(int argc, char* argv[])
{
    try {

        //parse command line parameters
        for (unsigned char i = 1; i < (unsigned char)argc; ++i)
        {

            //I/O YUV files
            if (strcmp(argv[i], "-m") == 0)
            {
                if (++i < argc)
                {
                    if (strcmp(argv[i], "words") == 0)
                        m_Mode = WORDS_MODE;
                    else if (strcmp(argv[i], "checksum") == 0)
                        m_Mode = CHECKSUM_MODE;
                    else
                        throw std::string("ERROR: Incorrect mode");
                }
                else
                    throw std::string("ERROR: Empty mode");
            }
            else if (strcmp(argv[i], "-f") == 0)
                m_FileName = GetStringArgument(argv, ++i, argc);
            else if (strcmp(argv[i], "-v") == 0)
                m_NeededWord = GetStringArgument(argv, ++i, argc);
            //help
            else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
                m_bPrintHelp = true;
            else
                throw std::string("ERROR: Unknown input argument");
        }

        if (m_bPrintHelp)
        {
            PrintHelp();
            return -1;
        }

        // Check on errors
        if (m_Mode == UNDEFINED_MODE)
            throw std::string("ERROR: Undefined mode");

        if (m_FileName.empty())
            throw std::string("ERROR: No input file. Please, add input file to CMD: -f [input_file_name]");

        if (m_Mode == WORDS_MODE && m_NeededWord.empty())
            throw std::string("ERROR: No needed word in the 'words' mode. Please, add needed word: -v [needed_word]");

        // Warnings
        if (m_Mode == CHECKSUM_MODE && !m_NeededWord.empty())
            std::cout << "WARNING: option -v [needed_word] will be ignored in the 'checksum' mode" << std::endl;

    }
    catch (std::string& e) {
        std::cout << e << std::endl;
        throw std::string("ERROR: InputParams::ParseInputString");
    }

    return 0;
}

std::string InputParams::GetStringArgument(char* argv[], unsigned char index, int nArgNum)
{
    if (argv == nullptr || *argv == nullptr)
        throw std::string("ERROR: GetStringArgument: null pointer reference");
    if (index < nArgNum)
        return std::string(argv[index]);
    else
        throw std::string("ERROR: missing secondary string argument");
}
