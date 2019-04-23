#include <string.h> 
#include "Cyphers.h"

void CaesarshiftEncrypt (char x[], int y){
    int r;
    int Stop = strlen(x);
    while (r < Stop) {
        
        if (64 < x[r] && x[r]< 91){
            x[r] += y;
                if (x[r] > 90){
                    x[r] -= 26;
                }
        }

        else if (96 < x[r] && x[r] < 123){
            x[r] += y;
                if (x[r] > 122){
                    x[r] -= 26;
                }
            x[r] -= 32;
        }
        
        else {}
        r++;
    }
}


void CaesarshiftDecrypt (char x[], int y){
    int r;
    int Stop = strlen(x);
    while (r < Stop) {
        
        if (64 < x[r] && x[r]< 91){
            x[r] -= y;
                if (x[r] < 65){
                    x[r] += 26;
                }
        }

        else if (96 < x[r] && x[r] < 123){
            x[r] -= y;
                if (x[r] < 97){
                    x[r] += 26;
            x[r] -= 32;
                }
        }
        
        else {}
        r++;
    }
}