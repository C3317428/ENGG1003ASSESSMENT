#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "Cyphers.h"

int main0() {
	char Filename[30]; // This is an array that will store the file name that the user wishes to run the program on.
	static char String[1000]; // This is an array that will store the characters from the file.
	
	printf("Hello there! \nWelcome to my encoder/decoder. \nPlease enter the name of the file to be read to continue.");
	
	printf("\nEnter here: ");	
	scanf("%[^\n]%*c", Filename);  // This takes key inputs from the user and stores them as a string in 'a'. Stops taking inputs when the enter key is pressed.
	
	FILE *input;
 	input = fopen(Filename, "r"); 
        
    if (input == NULL) {
        printf("\nCan't open that input file! \nPlease check the name and try again.\n");
        return 0;
        }
    
    int x = 0;
    while (!feof(input)) {     
        fscanf(input, "%c", &String[x]);
        x++;
        
        if (feof(input) != 0){
            String[x] = '\0';
            }
        
        }
	    printf("%s", String);
	
	return 0;
}
/*printf("Option 1: Caesar Encrypt \nOption 2: Caesar Decrypt \nOption 3: Substitution Encrypt \nOption 4: Substitution Decrypt\n");*/