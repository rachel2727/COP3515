// Rachel Singh
// Adv Program Design
// AHPA #5: Caesar's Cipher

#include <stdio.h>
#include <ctype.h>
#define LEN 23

int main()
{

    // intializing file pointer variables and the cipher array for the string.
    
    char cipher[LEN];
    FILE* fptr;
    FILE* fp;

    // opening the file clearMessage.txt and verifying there is no error. 

    fptr = fopen("clearMessage.txt", "r");
    
    if(fptr == NULL)
    {
        printf("There was an error.\n");
        return 0;
    }    

    // looping through the file to get single characters.

    for(int i = 0; i < LEN; i++)
    {
        cipher[i] = fgetc(fptr);
    }

    // utilizing isalpha() to convert letters only to +3 in ascii.

    for(int i = 0; i < LEN; i++)
    {
        if (isalpha(cipher[i]) != 0)
        {
            cipher[i] = cipher[i] + 3;
        }
    }

    // opening the new file and writing the secret message into it.

    fp = fopen("secretMessage.txt", "w");

    for(int i = 0; i < LEN; i++)
    {
        fprintf(fp, "%c", cipher[i]);
    }

    // closing the read and write files.

    fclose(fptr);
    fclose(fp);

    return 0;

}