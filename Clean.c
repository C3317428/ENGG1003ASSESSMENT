#include <stdio.h>
#include <string.h> 
#include "Cyphers.h"  /* Include the header here, to obtain the function declaration */

int main(void)
{
    char caesar[] = {"MY NAME IS ROGER AND I AM A MAGICAL BUNNY RABBIT"}; 
    /*Translates to "MY NAME IS ROGER AND I AM A MAGICAL BUNNY RABBIT" after using a 7-key rotation*/
    CaesarshiftEncrypt (caesar, 7);
    
    printf ("%s", caesar);

	return 0;
    
}