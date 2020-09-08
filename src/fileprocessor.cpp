#include <fileprocessor.h>

FileProcessor::FileProcessor(const std::string fileName)
{
    m_sFile.open(fileName.c_str());

    if (!m_sFile.is_open())
    {
        throw std::string("ERROR: FileProcessor::FileProcessor: file wasn't opened");
    }
}

std::ifstream& FileProcessor::GetRefFileStream()
{
    return m_sFile;
}