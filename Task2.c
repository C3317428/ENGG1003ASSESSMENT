#include <stdio.h>
#include <string.h> 

void CaesarshiftDecrypt (char x[], int y);

int main() {
	char caesar[] = {"TF UHTL PZ YVNLY HUK P HT H THNPJHS IBUUF YHIIPA"}; 
    /*Translates to "MY NAME IS ROGER AND I AM A MAGICAL BUNNY RABBIT" after using a 7-key rotation*/
    CaesarshiftDecrypt (caesar, 7);
    
    printf ("%s", caesar);

	return 0;
}

void CaesarshiftDecrypt (char x[], int y){
    int r;
    int Stop = strlen(x);
    for (r = 0; r < Stop; r++) {
        x[r] -= y;
        if (x[r] == 32 - y) {
            x[r] = 32;
        }       
        else if (x[r] < 65) {
            x[r] += 26;
        }
        else{}
    }
}
