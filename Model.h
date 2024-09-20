/// @file <Model.h>
/// @brief <Header file to initiate the functions for Model.cpp>
/// @author <Joshua Fisher>
#ifndef MODEL_H
#define MODEL_H

#include <iostream>
//Saw it online
#include <cctype>
using namespace std;

class Model {
    public:
        Model(); //default constructor
       
        ~Model(); //destructor

        // Methods
        string translateSingleConsonant(char consonant);
        string translateSingleVowel(char vowel);
    private:
};
#endif