#include <string.h>  //Includes the string library
#include "Cyphers.h" //Includes the function prototypes from Cyphers.h


void RotationEncrypt (char x[], int Key){
    int r = 0;            //Array element number, determines which part of the array is accessed
    int Stop = strlen(x); //Makes stop the length of the string
    while (r < Stop) {    //While the array element number is lower than the size of the array
        
        if (96 < x[r] && x[r] < 123){ //If the letter is lowercase
            x[r] -= 32;               //Make it uppercase
        }
                
        if (64 < x[r] && x[r]< 91){ //If it is an uppercase letter
            x[r] += Key;            //Uses the key to rotate the letter forwards through the alphabet
                if (x[r] > 90){     //If the letter goes past 'Z'
                    x[r] -= 26;     //Loop back around towards the start of the alphabet
                }
        }
        
        else {} //If it's not an uppercase letter, don't change it
        r++;    // r increments by 1, moving the loop onto the next character in the array
    }
}


void RotationDecrypt (char x[], int Key){
    int r = 0;            //Array element number, determines which part of the array is accessed
    int Stop = strlen(x); //Makes stop the length of the string
    while (r < Stop) {    //While the array element number is lower than the size of the array
        
        if (x[r] > 96 && x[r] < 123){ //If the letter is lowercase
            x[r] -= 32;               //Make it uppercase
        }
        
        if (64 < x[r] && x[r]< 91){ //If it is an uppercase letter
            x[r] -= Key;            //Uses the key to rotate the letter back through the alphabet
                if (x[r] < 65){     //If the letter goes past 'A'
                    x[r] += 26;     //Loop back around towards the end of the alphabet
                }
        }
        
        else {} //If it's not an uppercase letter, don't change it
        r++;    // r increments by 1, moving the loop onto the next character in the array
    }
}


void SubstitutionEncrypt (char x[], char Key[]) {
    char Alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //The standard alphabet, is used for comparison
    int r;                //Alphabet array element number, used to check if letters correspond with each other
    int n = 0;            //Array element number, determines which part of the array is accessed    
    int Stop = strlen(x); //Makes stop the length of the string
    
    while (n < Stop) {                //While the array element number is lower than the size of the array
        if (x[n] > 96 && x[n] < 123){ //If the letter is lowercase
            x[n] -= 32;               //Make it uppercase
        }
        
        for (r = 0; r < 26; r++) {      //For every letter in the alphabet
            if (x[n] == Alphabet[r]) {  //If the current array element is equal to the current letter of the alphabet
                x[n] = Key[r];          //The current array element is changed to the letter in the key with the same array element number as the matching letter from above
                break;                  //Stop trying to Encrypt
            } 
        }
     n++; //n increments by 1, moving the loop onto the next character in the array
    }   
}


void SubstitutionDecrypt (char x[], char Key[]) {
    char Alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //The standard alphabet, is used for comparison
    int r;                //Alphabet array element number, used to check if letters correspond with each other
    int n = 0;            //Array element number, determines which part of the array is accessed        
    int Stop = strlen(x); //Makes stop the length of the string
    
    while (n < Stop) {                //While the array element number is lower than the size of the array
        if (x[n] > 96 && x[n] < 123){ //If the letter is lowercase
            x[n] -= 32;               //Make it uppercase
        }
               
        for (r = 0; r < 26; r++) {     //For every letter in the alphabet
            if (x[n] == Key[r]) {      //If the current array element is equal to the current letter of the key
                x[n] = Alphabet[r];    //The current array element is changed to the letter in the alphabet with the same array element number as the matching letter from above
                break;                 //Stop trying to decrypt
            }   
        }
     n++; //n increments by 1, moving the loop onto the next character in the array
    }   
}
