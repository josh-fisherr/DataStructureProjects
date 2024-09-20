/// @file <Model.cpp>
/// @brief <Does the acutual translating of the Consonants and Vowels>
/// @author <Joshua Fisher>

#include "Model.h"

//Constructor
Model::Model(){

}

//Destructor
Model::~Model(){

}

string Model::translateSingleConsonant(char consonant) {
        // returns the translated consonant as a string
        return string(1, consonant) + "o" + string(1, consonant);
    }  

string Model::translateSingleVowel(char vowel) {
        // returns the vowel as the same but as a string
        return string(1, vowel);
    }