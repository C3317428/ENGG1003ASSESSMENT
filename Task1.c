#include <stdio.h>
#include <string.h> 

void CaesarshiftEncrypt (char x[], int y);

int main() {
	char caesar[] = {"MY NAME IS ROGER AND I AM A MAGICAL BUNNY RABBIT"}; 
    /*Translates to "TF UHTL PZ YVNLY HUK P HT H THNPJHS IBUUF YHIIPA" after using a 7-key rotation*/
    CaesarshiftEncrypt (caesar, 7);
    
    printf ("%s", caesar);

	return 0;
}

void CaesarshiftEncrypt (char x[], int y){
    int r;
    int Stop = strlen(x);
    for (r = 0; r < Stop; r++) {
        x[r] += y;
        if (x[r] == 32 + y) {
            x[r] = 32;
        }       
        else if (x[r]> 90) {
            x[r] -= 26;
        }
        else{}
    }
}
