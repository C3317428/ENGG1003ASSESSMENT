#include <string.h>  //Includes the string library
#include "Cyphers.h" //Includes the function prototypes from Cyphers.h

/*A function declaration for the function 'RotationEncrypt()' which returns nothing and accepts a character array and 
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

/*A function declaration for the function 'RotationDecrypt()' which returns nothing and accepts a character array and 
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

/*A function declaration for the function 'SubstitutionEncrypt()' which returns nothing and accepts two character arrays 
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

/*A function declaration for the function 'SubstitutionDecrypt()' which returns nothing and accepts two character arrays 
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
/*void RotationCrack (char x[]){
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
    int SecondLargest;              //Declares an integer that will hold the second most frequent letter
    int ThirdLargest;               //Declares an integer that will hold the third most frequent letter
    int Location1 = 0;              //Declares an integer that will hold the array index of the most frequent letter 
    int Location2 = 0;              //Declares an integer that will hold the array index of the second most frequent letter 
    int Location3 = 0;              //Declares an integer that will hold the array index of the third most frequent letter 
    Largest = x[0];                 //Sets a base line that will be used in comparing the frequencies
    SecondLargest = x[0];           //Sets a base line that will be used in comparing the frequencies
    ThirdLargest = x[0];            //Sets a base line that will be used in comparing the frequencies
    int Temp1Largest;               //Will be used while swapping values later
    int Temp2Largest;               //Will be used while swapping values later
    int Temp1Location;              //Will be used while swapping values later
    int Temp2Location;              //Will be used while swapping values later
    
    for (int s = 1; s < 26; s++){   //For every number in the array 'Frequency'
        if (x[s] > Largest){        //If the number at the current element is bigger than the recorded largest
            
            Temp1Largest = Largest;     //Temporarily store the old largest value
            Temp1Location = Location1;  //Temporarily store the location of the old largest
            
            Temp2Largest = SecondLargest;//Temporarily store the old second largest value
            Temp2Location = Location2;   //Temporarily store the location of the old second largest
            
            Largest  = x[s];                //The current element becomes the recorded largest
            Location1 = s;                  //The location of the largest element is updated
            
            SecondLargest = Temp1Largest;   //The old largest value becomes the new second largest
            Location2 = Temp1Location;      //The location of the old largest becomes the location of the new second largest
            
            ThirdLargest = Temp2Largest;    //The old second largest value becomes the new third largest
            Location3 = Temp2Location;      //The location of the old second largest becomes the location of the new third largest
        }
        
        else if (x[s] > SecondLargest && x[s] < Largest){//If the current element is larger than the second and third largest but not the largest
            Temp2Largest = SecondLargest;         //Temporarily store the old second largest value
            Temp2Location = Location2;            //Temporarily store the location of the old second largest
            
            SecondLargest  = x[s];                //The current element becomes the recorded second largest
            Location2 = s;                        //The location of the second largest element is updated
            
            ThirdLargest = Temp2Largest;          //The old second largest value becomes the new third largest
            Location3 = Temp2Location;            //The location of the old second largest becomes the location of the new third largest
        }
        
        else if (x[s] > ThirdLargest && x[s] < SecondLargest){//If the current element is only larger than the third largest
            ThirdLargest  = x[s];                             //The current element becomes the recorded third largest
            Location3 = s;                                    //The location of the third largest element is updated
        }
    
    }
    
    
    
    ETA
    
    
    
    printf("%s", Message);           // Prints the encrypted Message to the screen
    fprintf(Output, "%s", Message);  // Writes the encrypted message to a text file called 'Output'
}*/
