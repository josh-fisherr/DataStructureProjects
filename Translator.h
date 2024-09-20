/// @file <Translator.h>
/// @brief <Header file to initiate the functions for Translator.cpp>
/// @author <Joshua Fisher>
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Model.h"
#include <iostream>
using namespace std;

class Translator {
    public:
    Translator(); //default constructor
       
    ~Translator(); //destructor

        // Methods
        string translateEnglishWord(string englishWord);
        string translateEnglishSentence(string englishSentence);

    private:
        Model *model;
};
#endif