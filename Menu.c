#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main() {
	char a[30];
	
	printf("Hello there! \nWelcome to my encoder/decoder, please enter the file name to read to continue to continue. \n");
	printf("Enter here: ");	
	scanf("%[^\n]%*c", a);
	
	FILE *Stuff;
 	Stuff = fopen(a, "r"); 
    if (Stuff == NULL) {
        fprintf(stderr, "Can't open input file\n");
        exit(1);}

    char file [400];
    while (!feof(Stuff)) {
        fscanf(Stuff, "%c", file);
        fprintf("%c", file);
        
    }
	
	return 0;
}


/*printf("Option 1: Caesar Encrypt \nOption 2: Caesar Decrypt \nOption 3: Substitution Encrypt \nOption 4: Substitution Decrypt\n");*/