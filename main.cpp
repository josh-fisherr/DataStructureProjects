/// @file <main.cpp>
/// @brief <Runs the codes and uses fileProcessor to run the acutual code>
/// @author <Joshua Fisher>

#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main(int argc, char **argv) {
// Create an instance of the Model class
   // Instantiate a FileProcessor
    FileProcessor fileProcessor;

    // Translate the provided input file to Rövarspråket using the file processor
    fileProcessor.processFile("original.txt", "translation.html");

    return 0; // Exit
}