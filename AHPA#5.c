// Rachel Singh
// Adv Program Design
// AHPA #5: Caesar's Cipher

#include <stdio.h>
#define LEN 35

int main()
{
    char cipher[LEN];
    FILE* fptr;

    fptr = fopen("clearMessage.txt", "r");

    if(fptr == NULL)
    {
        printf("There was an error.\n");
        exit(1);
    }

    for(int i = 0; i < LEN; i++)
    {
        cipher[i] = fgetc(fptr);
    }

    for(int i = 0; i < LEN; i++)
    {
        printf("%c", cipher[i]);
    }

}