/// @file <FileProcessor.cpp>
/// @brief <Processes the file to open and close for the translation of Rovarspraket>
/// @author <Joshua Fisher>

#include "FileProcessor.h"
#include "Model.h"
#include "Translator.h"

FileProcessor::FileProcessor(){
}

FileProcessor::~FileProcessor() {
}

void FileProcessor::processFile(string inputFile, string outputFile) {
    // Open the input file
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cerr << "Error opening input file: " << inputFile << endl;
        return; // Exit if the input file cannot be opened
    }

    // Open the output file
    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        //Just in case the file isn't there / not opened, logic from previos C++ project
        cerr << "Error opening output file: " << outputFile << endl;
        inFile.close(); // Close the input file
        return; // Exit if the output file cannot be opened
    }

string line;

Translator translator;
    while (getline(inFile, line)) {
        outFile << "<b>" << line << "</b><br>" << endl; // Original English text in bold
        outFile << "<i>" << translator.translateEnglishSentence(line) << "</i><br><br>" << endl; // Translated text in italics
    }

    // Close the files
    inFile.close();
    outFile.close();
}
