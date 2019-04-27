#ifndef CYPHERS_H_   /* I don't understand this black magic but it lets me use a header file */
#define CYPHERS_H_   /* which makes the code significantly easier to read. */

/* A function need to be declared before it can be used, otherwise the compiler will not know how to treat the function when it gets to it.
   Note: The function does not need to be defined here, only declared. */

void RotationEncrypt (char x[], int Key);  /* A function declaration for the function 'RotationEncrypt()' which returns nothing and accepts a character array and an integer as its arguments */
void RotationDecrypt (char x[], int Key);  /* A function declaration for the function 'RotationDecrypt()' which returns nothing and accepts a character array and an integer as its arguments */
void SubstitutionEncrypt (char x[], char Key[]);  /* A function declaration for the function 'SubstitutionEncrypt()' which returns nothing and accepts two character arrays as its arguments */
void SubstitutionDecrypt (char x[], char Key[]);  /* A function declaration for the function 'SubstitutionDecrypt()' which returns nothing and accepts two character arrays as its arguments */
void RotationCrack (char x[]);  /* A function declaration for the function 'RotationCrack()' which returns nothing and accepts a character array as its argument */
void SubstitutionCrack (char x[]);  /* A function declaration for the function 'SubstitutionCrack()' which returns nothing and accepts a character array as its argument */

#endif // More black magic.
