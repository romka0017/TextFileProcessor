#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "dataprocessor.h"

// Word finder
TEST_CASE("Find existing needed word", "[WordFinderProcessor::ProcessFileStream]")
{
    InputParams params;
    params.m_NeededWord = "intel";
    params.m_Mode = WORDS_MODE;
    params.m_FileName = "Test.txt";

    FileProcessor reader(params.m_FileName);
    WordFinderProcessor proc(params);
    proc.ProcessFileStream(reader.GetRefFileStream());

    REQUIRE(proc.GetResult() == 2);
}

TEST_CASE("Find not existing needed word", "[WordFinderProcessor::ProcessFileStream]")
{
    InputParams params;
    params.m_NeededWord = "amd";
    params.m_Mode = WORDS_MODE;
    params.m_FileName = "Test.txt";

    FileProcessor reader(params.m_FileName);
    WordFinderProcessor proc(params);
    proc.ProcessFileStream(reader.GetRefFileStream());

    REQUIRE(proc.GetResult() == 0);
}

// Checksum
TEST_CASE("Calculate checksum from not empty file", "[CheckSumProcessor::ProcessFileStream]")
{
    InputParams params;
    params.m_NeededWord = "intel";
    params.m_Mode = WORDS_MODE;
    params.m_FileName = "Test.txt";

    FileProcessor reader(params.m_FileName);
    CheckSumProcessor proc;
    proc.ProcessFileStream(reader.GetRefFileStream());

    REQUIRE(proc.GetResult() == 311301608);
}

// Checksum
TEST_CASE("Calculate checksum from empty file", "[CheckSumProcessor::ProcessFileStream]")
{
    InputParams params;
    params.m_NeededWord = "intel";
    params.m_Mode = WORDS_MODE;
    params.m_FileName = "Test2.txt";

    FileProcessor reader(params.m_FileName);
    CheckSumProcessor proc;
    proc.ProcessFileStream(reader.GetRefFileStream());

    REQUIRE(proc.GetResult() == 0);
}

//int main(int argc, char **argv) {
//
//    dns_cache.update("amd.com", "7.7.7.7");
//
//    return 0;
//}