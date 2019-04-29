#include <stdio.h>   //Includes the standard input/output library
#include <string.h>  //Includes the string library
#include "Cyphers.h" //Includes the function prototypes from Cyphers.h

/*A function definition for the function 'RotationEncrypt()' which returns nothing and accepts a character array and 
 *an integer as its arguments. It uses rotation encryption to encrypt the character array by the amount given by the 
 *integer received by the function. The int can't be higher than 26 or lower than 0.*/
void RotationEncrypt (char x[], int Key){
    int r = 0;            //Array element number, determines which part of the array is accessed
    int Stop = strlen(x); //Makes stop the length of the string
    while (r < Stop) {    //While the array element number is lower than the size of the array
        
        if (96 < x[r] && x[r] < 123){ //If the letter is lowercase
            x[r] -= 32;               //Make it uppercase
        }       
        if (64 < x[r] && x[r]< 91){ //If it is an uppercase letter
            x[r] += Key;            //Uses the key to rotate the letter forwards through the alphabet
                if (x[r] > 90){     //If the letter goes past 'Z'
                    x[r] -= 26;     //Loop back around towards the start of the alphabet
                }
        }
        else {} //If it's not an uppercase letter, don't change it
        r++;    // r increments by 1, moving the loop onto the next character in the array
    }
}

/*A function definition for the function 'RotationDecrypt()' which returns nothing and accepts a character array and 
 *an integer as its arguments. It uses rotation Decryption to decrypt the character array by the amount given by the 
 *integer received by the function. The int can't be higher than 26 or lower than 0.*/
void RotationDecrypt (char x[], int Key){
    int r = 0;            //Array element number, determines which part of the array is accessed
    int Stop = strlen(x); //Makes stop the length of the string
    while (r < Stop) {    //While the array element number is lower than the size of the array
        
        if (x[r] > 96 && x[r] < 123){ //If the letter is lowercase
            x[r] -= 32;               //Make it uppercase
        }
        
        if (64 < x[r] && x[r]< 91){ //If it is an uppercase letter
            x[r] -= Key;            //Uses the key to rotate the letter back through the alphabet
                if (x[r] < 65){     //If the letter goes past 'A'
                    x[r] += 26;     //Loop back around towards the end of the alphabet
                }
        }
        
        else {} //If it's not an uppercase letter, don't change it
        r++;    // r increments by 1, moving the loop onto the next character in the array
    }
}

/*A function definition for the function 'SubstitutionEncrypt()' which returns nothing and accepts two character arrays 
 *as its arguments. It uses substitution encryption to encrypt the 1st character array with the key given by the 2nd 
 *array received by the function. The 2nd array must have precisely 26 characters with no characters repeating.*/
void SubstitutionEncrypt (char x[], char Key[]) {
    char Alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //The standard alphabet, is used for comparison
    int r;                //Alphabet array element number, used to check if letters correspond with each other
    int n = 0;            //Array element number, determines which part of the array is accessed    
    int Stop = strlen(x); //Makes stop the length of the string
    
    while (n < Stop) {                //While the array element number is lower than the size of the array
        if (x[n] > 96 && x[n] < 123){ //If the letter is lowercase
            x[n] -= 32;               //Make it uppercase
        }
        
        for (r = 0; r < 26; r++) {      //For every letter in the alphabet
            if (x[n] == Alphabet[r]) {  //If the current array element is equal to the current letter of the alphabet
                x[n] = Key[r];          //The current array element is changed to the letter in the key with the same array element number as the matching letter from above
                break;                  //Stop trying to Encrypt
            } 
        }
     n++; //n increments by 1, moving the loop onto the next character in the array
    }   
}

/*A function definition for the function 'SubstitutionDecrypt()' which returns nothing and accepts two character arrays 
 *as its arguments. It uses substitution decryption to decrypt the 1st character array with the key given by the 2nd 
 *array received by the function. The 2nd array must have precisely 26 characters with no characters repeating.*/
void SubstitutionDecrypt (char x[], char Key[]) {
    char Alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //The standard alphabet, is used for comparison
    int r;                //Alphabet array element number, used to check if letters correspond with each other
    int n = 0;            //Array element number, determines which part of the array is accessed        
    int Stop = strlen(x); //Makes stop the length of the string
    
    while (n < Stop) {                //While the array element number is lower than the size of the array
        if (x[n] > 96 && x[n] < 123){ //If the letter is lowercase
            x[n] -= 32;               //Make it uppercase
        }
               
        for (r = 0; r < 26; r++) {     //For every letter in the alphabet
            if (x[n] == Key[r]) {      //If the current array element is equal to the current letter of the key
                x[n] = Alphabet[r];    //The current array element is changed to the letter in the alphabet with the same array element number as the matching letter from above
                break;                 //Stop trying to decrypt
            }   
        }
     n++; //n increments by 1, moving the loop onto the next character in the array
    }   
}
/*A function definition for the function 'RotationCrack()' which returns nothing and accepts a character array 
 *as its argument. It uses rotation decryption and statistical analysis to decrypt the character array with no key given. Writes the
 *three most likely solutions to the output file and prints the most likely to the screen. */
void RotationCrack (char x[]){
    int Frequency[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Creates an array for counting the frequency of letters
    char Alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //The standard alphabet, is used for comparison
    int n = 0;            //Array element number, determines which part of the array is accessed        
    int Stop = strlen(x); //Makes stop the length of the string
    
    while (n < Stop) {                //While the array element number is lower than the size of the array
        if (x[n] > 96 && x[n] < 123){ //If the letter is lowercase
            x[n] -= 32;               //Make it uppercase
        }
               
        for (int r = 0; r < 26; r++) { //For every letter in the alphabet
            if (x[n] == Alphabet[r]) { //If the current array element is equal to the current letter of the alphabet
                Frequency[r] ++;       //Then the counter for that letter increases
                break;                 //Move onto next letter
            }   
        }
     n++; //n increments by 1, moving the loop onto the next character in the array
    }   
    
    
    int Largest;                    //Declares an integer that will hold the most frequent letter
    int Location = 0;               //Declares an integer that will hold the array index of the most frequent letter 
    Largest = x[0];                 //Sets a base line that will be used in comparing the frequencies
    
    for (int s = 1; s < 26; s++){   //For every number in the array 'Frequency'
        if (x[s] > Largest){        //If the number at the current element is bigger than the recorded largest
            Largest  = x[s];                //The current element becomes the recorded largest
            Location = s;                   //The location of the largest element is updated 
        }
    }
    char MFL = Alphabet[Location - 1]; //Sets a character called 'MFL' to the most frequent letter
    
    int Key1 = MFL - 69; //Determines the key if the most frequent letter decrypts to E
     Key1 = Key1 % 26;
     if (Key1 < 0){                                  //If in determining the key we accidentally create a negative
         Key1 = -(Key1);                                 //Loop it back around into a reasonable number
     }
    int Key2 = MFL - 84; //Determines the key if the most frequent letter decrypts to T
     Key2 = Key2 % 26;
     if (Key2 < 0){                                  //If in determining the key we accidentally create a negative
         Key2 = -(Key2);                                 //Loop it back around into a reasonable number
     }
    int Key3 = MFL - 65; //Determines the key if the most frequent letter decrypts to A
     Key3 = Key3 % 26;
     if (Key3 < 0){                                  //If in determining the key we accidentally create a negative
         Key3 = -(Key3);                                 //Loop it back around into a reasonable number
     }
    printf("%c", MFL);
    printf("%d, %d, %d", Key1, Key2, Key3);
    
    FILE *Output;                      //Creates a file pointer at Output
    Output = fopen("Output.txt", "w"); //Creates the file "Output.txt" for writing and allocates it to Output
    
    RotationDecrypt(x, Key1);  //Decrypts the message using the Key 1
    printf("%s", x);           //Prints the most probable decrypted Message to the screen
    fprintf(Output, "%s\n", x);//Writes the decrypted message to the output file
    RotationEncrypt(x, Key1);  //Re-encrypts the message using key 1 so that key 2 may be used on the unaltered message 
   
    RotationDecrypt(x, Key2);  //Decrypts the message using the Key 2
    fprintf(Output, "%s\n", x);//Writes the decrypted message to the output file
    RotationEncrypt(x, Key2);  //Re-encrypts the message using key 2 so that key 3 may be used on the unaltered message 
   
    RotationDecrypt(x, Key3);  //Decrypts the message using the Key 3
    fprintf(Output, "%s", x);  //Writes the decrypted message to the output file
}
