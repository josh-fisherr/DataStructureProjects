/// @file <Translator.cpp>
/// @brief <Has the rules of when to translate>
/// @author <Joshua Fisher>

#include "Translator.h"
#include "Model.h"
//Need isPunct for translator.cpp for the if statement 
//Constructor
Translator::Translator(){
    model = new Model();
}

//Destructor
Translator::~Translator(){
    delete model;
}

// Check here for the consonant or vowel
//In model should be clean, won't need to check if it's a vowel or consonant just change it, English word will do all the checks
string Translator::translateEnglishWord(string englishWord) {
   
    string translatedWord;
    //Checks if the these vowels are contained within the word
    // need is punct in translate word since i wont change it like the vowels
    for(int i = 0; i < englishWord.size(); ++i) {
       if (tolower(englishWord[i] == 'a') || tolower(englishWord[i]  == 'e') || tolower(englishWord[i] == 'i') ||
            tolower(englishWord[i] == 'o') || tolower(englishWord[i]  == 'u')) {
            // Takes advantage of the previous functions defined in Model.h, to not need to do repetitive code
            translatedWord += model->translateSingleVowel(englishWord[i]); 
            // Else statement for the consonnats also taking advantage of the previous functions
        } else {
            translatedWord += model->translateSingleConsonant(englishWord[i]);
        }
    }
    return translatedWord;
}

//Adding each character of the word until there is a space or puncutation, using character checker
//ispunct for puncutation
//EnglishSentence should be parsing it but all would be in translate englishWord
//Dont need ispunct here
string Translator::translateEnglishSentence(string englishSentence) {
    // The translated sentence
    string translatedSentence;
    for(int i = 0; i < englishSentence.size(); ++i) {
        //if there is punctuation in the sentence
        if (ispunct(englishSentence[i])) {
            // If it's punctuation, append directly to the translated sentence
            translatedSentence += englishSentence[i];
        } else {
            // Translate the single character
            string translatedWord = translateEnglishWord(string(1, englishSentence[i]));  
            // Append the translated word to the translated sentence
            translatedSentence += translatedWord;  
        }
    }
    return translatedSentence;
}
