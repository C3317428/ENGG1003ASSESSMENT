/*This is a rotation/substitution encrypter/decrypter. It reads a file encodes or decodes it and then prints the results
 *to the screen and to a new text file. An example of the required formatting for the input file is included with this 
 *assessment. Please check the file branch called "RequiredCommits" to find the commits needed for marks.
 *The tasks are: 1 Rotation Encrypt with key, 2 Rotation Decrypt with key, 3 Substitution Encrypt with key,
 *               4 Substitution Decrypt with key, 5 Rotation Decrypt without key, 6 Substitution Decrypt without key.
 */

#include <stdio.h>   //Includes the standard Input/Output library
#include <string.h>  //Includes the string library
#include <stdlib.h>  //Includes standard library definitions
#include "Cyphers.h" //Includes my cypher library

int main() {
	printf("Hello there! \nWelcome to my encoder/decoder.\nIt reads text file in the folder this file \nis located in titled 'Input.txt'.\nThere is a limit of 10000 characters.\n\n");
	//^ This just prints a welcome message when the program is booted
	
	FILE *Input;                     // Creates a file pointer at Input
 	Input = fopen("Input.txt", "r"); // Opens the file "Input.txt" for reading and allocates it to Input
    if (Input == NULL) {             // If the file can't be found
        printf("Can't open that input file! \nPlease check the name and try again.\n"); // Print an error message
        return 0;                    // End the program
        }
    
    FILE *Output;                      // Creates a file pointer at Output
    Output = fopen("Output.txt", "w"); // Creates the file "Output.txt" for writing and allocates it to Output
    
    fseek (Input, 1, SEEK_SET);        // Move the cursor in the Input file to right after the '#' symbol
    
    char Type = fgetc(Input);          // Sets the character 'Type' to the 2nd character in the file
    int  ArrayP = 0;                   // Array pointer, used for writing the input file to a character array
    int  RKeyD1 = 0;                   // An integer with the value of the first digit of the rotation cypher key
    int  RKeyD2 = 0;                  // An integer with the value of the second digit of the rotation cypher key
    int  RKeyT;                        // An integer with the value of the actual value of the rotation cypher key
    char SKey[26];                     // A character array that will contain the substitution key
    char Message [10000];              // A character array that will contain the message to be encoded/decoded
    
    
    for (int x = 0; x < 10000; x++){   // This loop sets the entire array to NULL
        Message[x] = 0;
    }
    
    switch (Type) {   // This checks the character that was the 2nd character in the input file and enacts the corresponding task
            
        case '1':                             // If Type is '1'
            printf("Rotation Encrypt:\n");    // Prints the name of the task to the sceen followed by a new line
            fseek (Input, 5, SEEK_SET);       // Sets the cursor in the input file to in front of the 1st key digit
            RKeyD1 = (int) fgetc(Input) - 48; // Sets RKeyD1 to the interger corresponding to the character read from the file (i.e. "2" becomes 2)
                if (RKeyD1 == 0 || RKeyD1 == 1 || RKeyD1 == 2){ // If the first digit of the key is 0, 1, or 2
                    
                    fseek (Input, 6, SEEK_SET);       // Move the cursor in the input file to in front of the 2nd key digit
                    RKeyD2 = (int) fgetc(Input) - 48; // Sets RKeyD2 to the interger corresponding to the character read from the file
                    
                    if (RKeyD2 < 0 || RKeyD2 > 9){    // If the value of RKeyD2 is less than 0 or RKeyD2 is greater than 9
                        RKeyT = RKeyD1;               // The actual value of the rotation key is just RKeyD1 with no weighting
                    }
                    else {                            // If RKeyD2 is in the range 0-9
                        RKeyD1 = RKeyD1 * 10;         // RKeyD1 is multiplied by 10 to give it a weighting of 10
                        RKeyT = RKeyD1 + RKeyD2;      // RKeyT equals RKeyD1 (tens) + RKeyD2 (units)
                    }
                } 
                
                else {                                // If the first digit is not 0, 1, or 2
                    RKeyT = RKeyD1;                   // The actual value of the rotation key is just RKeyD1 with no weighting
                }   
            while (!feof(Input)) {                      // While not at the end of the file
                fscanf(Input, "%c", &Message[ArrayP]);  // Scans a character from the input file and enters it into the array 'Message' at element 'ArrayP'
                ArrayP++;                               // Increments ArrayP by 1, moving the array 'Message' onto the next element
            }
                
            RotationEncrypt(Message, RKeyT); // Passes the array 'Message' and the integer RKeyT to the function RotationEncrypt
            printf("%s", Message);           // Prints the encrypted Message to the screen
            fprintf(Output, "%s", Message);  // Writes the encrypted message to a text file called 'Output'
        break;                               // Ends the switch case
            
            
        case '2':                             // If Type is '2'
            printf("Rotation Decrypt:\n");    // Prints the name of the task to the sceen followed by a new line
            fseek (Input, 5, SEEK_SET);       // Sets the cursor in the input file to in front of the 1st key digit
            RKeyD1 = (int) fgetc(Input) - 48; // Sets RKeyD1 to the interger corresponding to the character read from the file (i.e. "2" becomes 2)
                if (RKeyD1 == 0 || RKeyD1 == 1 || RKeyD1 == 2){ // If the first digit of the key is 0, 1, or 2
                    
                    fseek (Input, 6, SEEK_SET);       // Move the cursor in the input file to in front of the 2nd key digit
                    RKeyD2 = (int) fgetc(Input) - 48; // Sets RKeyD2 to the interger corresponding to the character read from the file
                    
                    if (RKeyD2 < 0 || RKeyD2 > 9){    // If the value of RKeyD2 is less than 0 or RKeyD2 is greater than 9
                        RKeyT = RKeyD1;               // The actual value of the rotation key is just RKeyD1 with no weighting
                    }
                    else {                            // If RKeyD2 is in the range 0-9
                        RKeyD1 = RKeyD1 * 10;         // RKeyD1 is multiplied by 10 to give it a weighting of 10
                        RKeyT = RKeyD1 + RKeyD2;      // RKeyT equals RKeyD1 (tens) + RKeyD2 (units)
                    }
                } 
                
                else {                                // If the first digit is not 0, 1, or 2
                    RKeyT = RKeyD1;                   // The actual value of the rotation key is just RKeyD1 with no weighting
                }
                   
            while (!feof(Input)) {                      // While not at the end of the file
                fscanf(Input, "%c", &Message[ArrayP]);  // Scans a character from the input file and enters it into the array 'Message' at element 'ArrayP'
                ArrayP++;                               // Increments ArrayP by 1, moving the array 'Message' onto the next element
            }
                               
            RotationDecrypt(Message, RKeyT); // Passes the array 'Message' and the integer RKeyT to the function RotationDecrypt
            printf("%s", Message);           // Prints the encrypted Message to the screen
            fprintf(Output, "%s", Message);  // Writes the encrypted message to a text file called 'Output'
        break;                               // Ends the switch case
            
            
        case '3':                                                 // If Type is '3'
            printf("Substitution Encrypt:\n");                    // Prints the name of the task to the sceen followed by a new line
                for (int Indicator = 5; Indicator < 32; Indicator++){ // For cursor locations 6 to 31
                    fseek (Input, Indicator, SEEK_SET);               // Read from the Input file at the current cursor location
                    SKey[ArrayP] = fgetc(Input);                      // Put the character read into the corresponding element of the SubstitutionKey array
                    ArrayP++;                                         // Increment ArrayP by 1 to move on to the next element of the array
                }            
            ArrayP = 0;                                           // Resets ArrayP to 0

            fseek (Input, 33, SEEK_SET);                   // Sets the cursor in the input file to in front of the encrypted letters
                while (!feof(Input)) {                     // While not at the end of the file
                    fscanf(Input, "%c", &Message[ArrayP]); // Scans a character from the input file and enters it into the array 'Message' at element 'ArrayP'
                    ArrayP++;                              // Increments ArrayP by 1, moving the array 'Message' onto the next element
                }
                
            SubstitutionDecrypt(Message, SKey); // Passes the array 'Message' and the array 'SKey' to the function SubstitutionEncrypt
            printf("%s", Message);              // Prints the encrypted Message to the screen
            fprintf(Output, "%s", Message);     // Writes the encrypted message to a text file called 'Output'
        break;                                  // Ends the switch case
            
            
        case '4':                                                 // If Type is '4'
            printf("Substitution Decrypt:\n");                    // Prints the name of the task to the sceen followed by a new line
                for (int Indicator = 5; Indicator < 32; Indicator++){ // For cursor locations 6 to 31
                    fseek (Input, Indicator, SEEK_SET);               // Read from the Input file at the current cursor location
                    SKey[ArrayP] = fgetc(Input);                      // Put the character read into the corresponding element of the SubstitutionKey array
                    ArrayP++;                                         // Increment ArrayP by 1 to move on to the next element of the array
                }            
            ArrayP = 0;                                           // Resets ArrayP to 0
                
            fseek (Input, 33, SEEK_SET);                // Sets the cursor in the input file to in front of the encrypted letters
                while (!feof(Input)) {                      // While not at the end of the file
                    fscanf(Input, "%c", &Message[ArrayP]);  // Scans a character from the input file and enters it into the array 'Message' at element 'ArrayP'
                    ArrayP++;                               // Increments ArrayP by 1, moving the array 'Message' onto the next element
                }
                
            SubstitutionDecrypt(Message, SKey); // Passes the array 'Message' and the array 'SKey' to the function SubstitutionDecrypt
            printf("%s", Message);              // Prints the encrypted Message to the screen
            fprintf(Output, "%s", Message);     // Writes the encrypted message to a text file called 'Output'
        break;                                  // Ends the switch case
            
        case '5':                            // If Type is '5'
            printf("Rotation Crack:\n");     // Prints the name of the task to the sceen followed by a new line            
            fseek (Input, 4, SEEK_SET);      // Sets the cursor in the input file to in front of the encrypted letters
                        
                while (!feof(Input)) {                      // While not at the end of the file
                    fscanf(Input, "%c", &Message[ArrayP]);  // Scans a character from the input file and enters it into the array 'Message' at element 'ArrayP'
                    ArrayP++;                               // Increments ArrayP by 1, moving the array 'Message' onto the next element
                }
                
            RotationCrack(Message);        // Passes the array 'Message' to the function RotationCrack
        break;                               // Ends the switch case
            
        case '6':                            // If Type is '6'
            printf("Substitution Crack:\n"); // Prints the name of the task to the sceen followed by a new line
            fseek (Input, 4, SEEK_SET);      // Sets the cursor in the input file to in front of the encrypted letters 
                        
                while (!feof(Input)) {                      // While not at the end of the file
                    fscanf(Input, "%c", &Message[ArrayP]);  // Scans a character from the input file and enters it into the array 'Message' at element 'ArrayP'
                    ArrayP++;                               // Increments ArrayP by 1, moving the array 'Message' onto the next element
                }
                
            //SubstitutionCrack(Message);    // Passes the array 'Message' to the function SubstitutionCrack
            printf("%s", Message);           // Prints the encrypted Message to the screen
            fprintf(Output, "%s", Message);  // Writes the encrypted message to a text file called 'Output'
        break;                               // Ends the switch case
            
        default:
            printf("Something went wrong with the task selection!"); // Prints an error message if the task choice fails
    }
    printf("\n"); // Adds a new line at the end of the program for formatting purposes
 
return 0;     // Ends the program
}
