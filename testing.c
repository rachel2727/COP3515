#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
int main()
{
    char str[MAX_LEN];
    char test[MAX_LEN];
    int count = 0;
    char list[MAX_LEN];
   
    FILE* pFile;
    pFile = fopen("Proposed passwords #1.txt", "r");
    if (pFile == NULL)
    {
        printf ("Error opening file\n");
        return 1;
    }

    char a[20]="Program";
    char b[20]={'P','r','o','g','r','a','m','o','\0'};
    char thingy[2][4] = { "funn", "read"};
   // printf("Length of string a = %d \n",strnlen(a,100));
//calculates the length of string before null character.
   // printf("Length of string b = %d \n",strnlen(b,100));
    for(int i = 0; i < 2; i++)
    {
        for( int j = 0; j < strlen(thingy[i]); j++)
            if(strchr(thingy[i], thingy[i][j]) != NULL)
            {
                //printf("This is character: %c and this is string: %s\n", thingy[i], thingy[i][j]);
            }
    }

    for(int i = 0; i < strlen(b); i++)
    {
        if(strchr(b, b[i]) != NULL)
            printf("Something is equal here.");
    }

    printf("%d", count);
    
    return 0;
}
