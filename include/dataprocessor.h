#ifndef __DATA_PROCESSOR_H__
#define __DATA_PROCESSOR_H__

#include <vector>
#include "fileprocessor.h"
#include "inputparameters.h"

class DataProcessor
{
public:

    ~DataProcessor() {};
    virtual void ProcessFileStream(std::ifstream& inFileStream) {};
    virtual void PrintResult() const {};
    virtual uint32_t GetResult() const { return -1; };

protected:

    DataProcessor() {};
};


class WordFinderProcessor : public DataProcessor
{
public:

    WordFinderProcessor(const InputParams& params);
    void ProcessFileStream(std::ifstream& inFileStream) override;
    void PrintResult() const override;
    uint32_t GetResult() const override;

private:

    std::string ReadOneLine(std::ifstream& inFileStream);

    uint32_t m_numberOccurrences = 0;
    std::string m_neededWord;
};



class CheckSumProcessor : public DataProcessor
{
public:

    void ProcessFileStream(std::ifstream& inFileStream) override;
    void PrintResult() const override;
    uint32_t GetResult() const override;

private:

    uint32_t m_checkSum = 0;
};

#endif // __DATA_PROCESSOR_H__