#include <string.h> 
#include "Cyphers.h"

void RotationEncrypt (char x[], int Key){
    int r;
    int Stop = strlen(x);
    while (r < Stop) {
        
        if (64 < x[r] && x[r]< 91){
            x[r] += Key;
                if (x[r] > 90){
                    x[r] -= 26;
                }
        }

        else if (96 < x[r] && x[r] < 123){
            x[r] += Key;
                if (x[r] > 122){
                    x[r] -= 26;
                }
            x[r] -= 32; //Turns the letter from lowercase to uppercase
        }
        else {}
        r++;
    }
}


void RotationDecrypt (char x[], int Key){
    int r;
    int Stop = strlen(x);
    while (r < Stop) {
        
        if (64 < x[r] && x[r]< 91){
            x[r] -= Key;
                if (x[r] < 65){
                    x[r] += 26;
                }
        }

        else if (96 < x[r] && x[r] < 123){
            x[r] -= Key;
                if (x[r] < 97){
                    x[r] += 26;
            x[r] -= 32; //Turns the letter from lowercase to uppercase
                }
        }
        else {}
        r++;
    }
}

void SubstitutionEncrypt (char x[], char Key[]) {
    char Alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int r;
    int n = 0;    
    int Stop = strlen(x);
    
    while (n < Stop) {
        if (x[n] > 96 && x[n] < 123){
            x[n] -= 32;
        }
        
        for (r = 0; r < 26; r++) {
            if (x[n] == Alphabet[r]) {
                x[n] = Key[r];
                break;
            } 
        }
     n++;
    }   
}

void SubstitutionDecrypt (char x[], char Key[]) {
    char Alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int r;
    int n = 0;    
    int Stop = strlen(x);
    
    while (n < Stop) {
        if (x[n] > 96 && x[n] < 123){
            x[n] -= 32;
        }
               
        for (r = 0; r < 26; r++) {
            if (x[n] == Key[r]) {
                x[n] = Alphabet[r];
                break;
            }   
        }
     n++; 
    }   
}
