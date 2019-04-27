#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "Cyphers.h"

int main() {
	printf("Hello there! \nWelcome to my encoder/decoder.\nIt reads text file in the folder this file \nis located in titled 'Input.txt'.\nThere is a limit of 2500 characters.\n\n");
	
	/* scanf("%[^\n]%*c", Filename); This takes key inputs from the user and stores them as a string in 'a'. Stops taking inputs when the enter key is pressed. 
	Not needed anymore but I thought it was really cool so I'm going to keep it here in a comment */
	
	FILE *Input;
 	Input = fopen("Input.txt", "r"); 
    if (Input == NULL) {
        printf("Can't open that input file! \nPlease check the name and try again.\n");
        return 0;
        }
    
    FILE *Output;
    Output = fopen("Output.txt", "w");
    
    fseek (Input, 1, SEEK_SET);
    
    char Type = fgetc(Input);
    int  ArrayP = 0;
    int  RKey;
    char SKey[26];
    char Message [10000];
    
    
    for (int x = 0; x < 2500; x++){ // This loop zeros the entire array
        Message[x] = 0;
    }
    
    switch (Type) {
            case '1':
                printf("Rotation Encrypt:\n");
                fseek (Input, 6, SEEK_SET);
                RKey = fgetc(Input);
        
                while (!feof(Input)) {     
                    char LFC; //Letter for cypher
                    fscanf(Input, "%c", &LFC);
                    Message[ArrayP] = LFC;
                    ArrayP++;
                }
                
                RotationEncrypt(Message, RKey);
                printf("%s", Message);
            break;
            
            case '2':
                printf("Rotation Decrypt:\n");
                fseek (Input, 6, SEEK_SET);
                RKey = fgetc(Input);
            
                while (!feof(Input)) {     
                    char LFC;
                    fscanf(Input, "%c", &LFC);
                    Message[ArrayP] = LFC;
                    ArrayP++;
                }
                
                RotationDecrypt(Message, RKey);
                printf("%s", Message);
                fprintf(Output, "%s", Message);
            break;
            
            case '3':
                printf("Substitution Encrypt:\n");
                for (int Indicator = 6; Indicator < 32; Indicator++){
                    fseek (Input, Indicator, SEEK_SET);
                    SKey[ArrayP] = fgetc(Input);
                    ArrayP++;
                }            
                ArrayP = 0;

                fseek (Input, 33, SEEK_SET);
                while (!feof(Input)) {     
                    char LFC;
                    fscanf(Input, "%c", &LFC);
                    Message[ArrayP] = LFC;
                    ArrayP++;
                }
                
                SubstitutionEncrypt(Message, SKey);
                printf("%s", Message);
                fprintf(Output, "%s", Message);
            break;
           
            case '4':
                printf("Substitution Decrypt:\n");
                for (int Indicator = 6; Indicator < 32; Indicator++){
                    fseek (Input, Indicator, SEEK_SET);
                    SKey[ArrayP] = fgetc(Input);
                    ArrayP++;
                }            
                ArrayP = 0;
                
                fseek (Input, 33, SEEK_SET);
                while (!feof(Input)) {     
                    char LFC;
                    fscanf(Input, "%c", &LFC);
                    Message[ArrayP] = LFC;
                    ArrayP++;
                }
                
                SubstitutionDecrypt(Message, SKey);
                printf("%s", SKey);
                printf("%s", Message);
                fprintf(Output, "%s", Message);
            break;
            
            case '5':
                printf("Rotation Crack:\n");            
                fseek (Input, 6, SEEK_SET);
                        
                while (!feof(Input)) {     
                    char LFC;
                    fscanf(Input, "%c", &LFC);
                    Message[ArrayP] = LFC;
                    ArrayP++;
                }
                
                //RotationCrack(Message);
                printf("%s", Message);
                fprintf(Output, "%s", Message);
            break;
            
            case '6':
                printf("Substitution Crack:\n");
                fseek (Input, 6, SEEK_SET);
                        
                while (!feof(Input)) {     
                    char LFC;
                    fscanf(Input, "%c", &LFC);
                    Message[ArrayP] = LFC;
                    ArrayP++;
                }
                
                //SubstitutionCrack(Message);
                printf("%s", Message);
                fprintf(Output, "%s", Message);
            break;
            
            default:
            printf("Something went wrong!");
        }
    printf("\n");
    
    
    fseek (Input, 0, SEEK_SET);
    
    
	return 0;
}
