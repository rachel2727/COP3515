#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLINE 100
#define MAXLEN 10000

void file_loader(FILE *pFile1);

int main()
{
    
    FILE* pFile1;
    FILE* pFile2;
    FILE* pFile3;
    pFile1 = fopen("Proposed Passwords #2.txt", "r");
    pFile2 = fopen("Proposed passwords #1.txt", "r");
    pFile3 = fopen("Proposed Passwords #3.txt", "r");

    
    if (pFile1 == NULL)
    {
        printf ("Error opening file\n");
        return 1;
    }
    
    file_loader(pFile1);
    file_loader(pFile2);
    file_loader(pFile3);
    return 0;

}

void file_loader(FILE *pFile1)
{
    int maxPass;
    int minPass;
    bool passPhrases = true; 
    bool optTests = true;
    int passPhrase_len;
    int optTest_min;
    char str[MAXLINE];
    char total_file[MAXLINE][MAXLEN];
    int line_count = 0;

    printf("Processing file #1...\n\n");

    //This is where we load files...

    while(fgets(str, MAXLEN, pFile1) != NULL)
    {   
        if(*str == '\n')
        {
            continue;
        }
        strcpy(total_file[line_count], str);
        line_count++;
    }
        
    maxPass = atoi(total_file[0]);
    minPass = atoi(total_file[1]);

    if(atoi(total_file[2]) == 1)
    {
        passPhrase_len = atoi(total_file[3]);
    }
    else
    {
        passPhrases = false;
    }

    if(atoi(total_file[4]) == 1)
    {
        optTest_min = atoi(total_file[5]);
    }
    else
    {
        optTests = false;
    }

    printf("Maximum password length: %d\n", maxPass);
    printf("Minimum password length: %d\n", minPass);

     if(passPhrases == false)
        printf("Pass phrases are NOT allowed.\n");
    else
        printf("Pass phrases are permitted.\n");
    
    if(optTests == false)
        printf("Optional Tests are NOT allowed.\n");
    else   
        printf("Optional Tests are permitted.\n");


    printf("\n");

    for(int i = 0; i <line_count; i++)
    {
        printf("%s", total_file[i]);
    }

}

