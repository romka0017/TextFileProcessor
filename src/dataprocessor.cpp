#include <dataprocessor.h>

// Word finder
WordFinderProcessor::WordFinderProcessor(const InputParams& params)
    : m_neededWord(params.m_NeededWord) {}

std::string WordFinderProcessor::ReadOneLine(std::ifstream& inFileStream)
{
    std::string outString;

    if (inFileStream.peek() == EOF)
    {
        return outString;
    }

    std::getline(inFileStream, outString);

    return outString;
}

void WordFinderProcessor::ProcessFileStream(std::ifstream& inFileStream)
{
    std::string oneString;
    while (!(oneString = ReadOneLine(inFileStream)).empty())
    {
        std::string::size_type pos = 0;
        while ((pos = oneString.find(m_neededWord, pos)) != std::string::npos)
        {
            if (pos + m_neededWord.size() < oneString.size())
                if (isalpha(oneString[pos + m_neededWord.size()]))
                {
                    pos = pos + m_neededWord.size();
                    continue;
                }

            m_numberOccurrences++;
            pos = pos + m_neededWord.size();
        }
    }
}

void WordFinderProcessor::PrintResult() const
{
    std::cout << "Number of the occurrences is: " << GetResult() << std::endl;
}

uint32_t WordFinderProcessor::GetResult() const
{
    return m_numberOccurrences;
}

// Checksum
void CheckSumProcessor::ProcessFileStream(std::ifstream& inFileStream)
{
    //std::string oneString;
    char wordchar[4] = {0};
    uint32_t* pWorduint32;

    while (!inFileStream.eof())
    {
        inFileStream.read(wordchar, 4);
        pWorduint32 = reinterpret_cast<uint32_t*>(wordchar);
        m_checkSum += *pWorduint32;
        memset(wordchar, 0, sizeof(wordchar));
    }
}

void CheckSumProcessor::PrintResult() const
{
    std::cout << "Checksum is: " << GetResult() << std::endl;
}

uint32_t CheckSumProcessor::GetResult() const
{
    return m_checkSum;
}