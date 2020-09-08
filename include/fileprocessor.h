#ifndef __FILE_PROCESSOR_H__
#define __FILE_PROCESSOR_H__

#include <fstream>

class FileProcessor
{
public:

    explicit FileProcessor(const std::string fileName);
    ~FileProcessor()
    {
        if (m_sFile.is_open())
            m_sFile.close();
    }

    std::ifstream& GetRefFileStream();

private:

    std::ifstream m_sFile;
};


#endif // __FILE_PROCESSOR_H__