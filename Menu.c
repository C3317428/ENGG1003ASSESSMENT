#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main() {
	char a[30];
	
	printf("Hello there! \nWelcome to my encoder/decoder, please enter the file name to read to continue to continue. \n");
	printf("Enter here: ");	
	scanf("%[^\n]%*c", a);
	
	FILE *input;
 	input = fopen(a, "r"); 
    if (input == NULL) {
        fprintf(stderr, "Can't open input file\n");
        exit(1);}


    while (!feof(input)) {   //TO DO Fix this shit here  
        char c;
        fscanf(*input, "%c", &c, );
        printf("%c", c);
        
    }
	
	return 0;
}


/*printf("Option 1: Caesar Encrypt \nOption 2: Caesar Decrypt \nOption 3: Substitution Encrypt \nOption 4: Substitution Decrypt\n");*/
