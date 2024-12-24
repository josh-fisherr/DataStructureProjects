/// @file <FileProcessor.h>
/// @brief <Header file to initiate the functions for FileProcesor.cpp>
/// @author <Joshua Fisher>
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
using namespace std;

class FileProcessor {
    public:
    FileProcessor(); //default constructor
       
    ~FileProcessor(); //destructor

    //Method
    void processFile(string inputFile, string outputFile);

    private:
    
};
#endif
